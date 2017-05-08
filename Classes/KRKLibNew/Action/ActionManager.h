#ifndef __ACTION_ACTION_MANAGER_H__
#define __ACTION_ACTION_MANAGER_H__

#include "Action/Action.h"
#include "Base/Vector.h"
#include "Base/Ref.h"


class Action;

struct _hashElement;

/**
 * @addtogroup actions
 * @{
 */

/** @class ActionManager
 @brief ActionManager is a singleton that manages all the actions.
 Normally you won't need to use this singleton directly. 99% of the cases you will use the Node interface,
 which uses this singleton.
 But there are some cases where you might need to use this singleton.
 Examples:
    - When you want to run an action where the target is different from a Node. 
    - When you want to pause / resume the actions.
 
 @since v0.8
 */
class ActionManager : public Ref
{
public:
    /**
     * @js ctor
     */
    ActionManager(void);

    /**
     * @js NA
     * @lua NA
     */
    ~ActionManager(void);

    // actions
    
    /** Adds an action with a target. 
     If the target is already present, then the action will be added to the existing target.
     If the target is not present, a new instance of this target will be created either paused or not, and the action will be added to the newly created target.
     When the target is paused, the queued actions won't be 'ticked'.
     *
     * @param action    A certain action.
     * @param target    The target which need to be added an action.
     * @param paused    Is the target paused or not.
     */
    void addAction(Action *action, Node *target, bool paused);

    /** Removes all actions from all the targets.
     */
    void removeAllActions();

    /** Removes all actions from a certain target.
     All the actions that belongs to the target will be removed.
     *
     * @param target    A certain target.
     */
    void removeAllActionsFromTarget(Node *target);

    /** Removes an action given an action reference.
     *
     * @param action    A certain target.
     */
    void removeAction(Action *action);

    /** Removes an action given its tag and the target.
     *
     * @param tag       The action's tag.
     * @param target    A certain target.
     */
    void removeActionByTag(int tag, Node *target);
    
    /** Removes all actions given its tag and the target.
     *
     * @param tag       The actions' tag.
     * @param target    A certain target.
     * @js NA
     */
    void removeAllActionsByTag(int tag, Node *target);

    /** Removes all actions matching at least one bit in flags and the target.
     *
     * @param flags     The flag field to match the actions' flags based on bitwise AND.
     * @param target    A certain target.
     * @js NA
     */
    void removeActionsByFlags(unsigned int flags, Node *target);

    /** Gets an action given its tag an a target.
     *
     * @param tag       The action's tag.
     * @param target    A certain target.
     * @return  The Action the with the given tag.
     */
    Action* getActionByTag(int tag, const Node *target) const;

    /** Returns the numbers of actions that are running in a certain target. 
     * Composable actions are counted as 1 action. Example:
     * - If you are running 1 Sequence of 7 actions, it will return 1.
     * - If you are running 7 Sequences of 2 actions, it will return 7.
     *
     * @param target    A certain target.
     * @return  The numbers of actions that are running in a certain target.
     * @js NA
     */
    long getNumberOfRunningActionsInTarget(const Node *target) const;

    /** Pauses the target: all running actions and newly added actions will be paused.
     *
     * @param target    A certain target.
     */
    void pauseTarget(Node *target);

    /** Resumes the target. All queued actions will be resumed.
     *
     * @param target    A certain target.
     */
    void resumeTarget(Node *target);
    
    /** Pauses all running actions, returning a list of targets whose actions were paused.
     *
     * @return  A list of targets whose actions were paused.
     */
    Vector<Node*> pauseAllRunningActions();
    
    /** Resume a set of targets (convenience function to reverse a pauseAllRunningActions call).
     *
     * @param targetsToResume   A set of targets need to be resumed.
     */
    void resumeTargets(const Vector<Node*>& targetsToResume);
    
    /** Main loop of ActionManager.
     * @param dt    In seconds.
     */
    void update(float dt);
    
protected:
    // declared in ActionManager.m

    void removeActionAtIndex(long index, struct _hashElement *element);
    void deleteHashElement(struct _hashElement *element);
    void actionAllocWithHashElement(struct _hashElement *element);

protected:
    struct _hashElement    *_targets;
    struct _hashElement    *_currentTarget;
    bool            _currentTargetSalvaged;
};


#endif // __ACTION_ACTION_MANAGER_H__
