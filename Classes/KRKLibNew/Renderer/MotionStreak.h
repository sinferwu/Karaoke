#ifndef __MOTION_STREAK_H__
#define __MOTION_STREAK_H__

#include "Renderer/Protocols.h"
#include "Renderer/Node.h"
#include "Renderer/CustomCommand.h"

class Texture2D;

class MotionStreak : public Node, public TextureProtocol
{
public:
    /** Creates and initializes a motion streak with fade in seconds, minimum segments, stroke's width, color, texture filename.
     *
     * @param fade The fade time, in seconds.
     * @param minSeg The minimum segments.
     * @param stroke The width of stroke.
     * @param color The color of stroke.
     * @param path The texture file name of stoke.
     * @return An autoreleased MotionStreak object.
     */
    static MotionStreak* create(float fade, float minSeg, float stroke, const Color3B& color, const std::string& path);
    /** Creates and initializes a motion streak with fade in seconds, minimum segments, stroke's width, color, texture.
     * 
     * @param fade The fade time, in seconds.
     * @param minSeg The minimum segments.
     * @param stroke The width of stroke.
     * @param color The color of stroke.
     * @param texture The texture name of stoke.
     * @return An autoreleased MotionStreak object.
     */
    static MotionStreak* create(float fade, float minSeg, float stroke, const Color3B& color, Texture2D* texture);

    /** Color used for the tint.
     *
     * @param colors The color used for the tint.
     */
    void tintWithColor(const Color3B& colors);

    /** Remove all living segments of the ribbon.
     */
    void reset();

    /** When fast mode is enabled, new points are added faster but with lower precision. 
     * 
     * @return True if fast mode is enabled.
     */
    inline bool isFastMode() const { return _fastMode; }
    /** Sets fast mode or not.
     *
     * @param bFastMode True if enabled fast mode.
     */
    inline void setFastMode(bool bFastMode) { _fastMode = bFastMode; }
    /** Get stroke.
     *
     * @return float stroke.
     */
    inline float getStroke() const { return _stroke; }
    /** Set stroke.
     *
     * @param stroke The width of stroke.
     */
    inline void setStroke(float stroke) { _stroke = stroke; }

    /** Is the starting position initialized or not.
     *
     * @return True if the starting position is initialized.
     */
    inline bool isStartingPositionInitialized() const { return _startingPositionInitialized; }
    /** Sets the starting position initialized or not.
     *
     * @param bStartingPositionInitialized True if initialized the starting position.
     */
    inline void setStartingPositionInitialized(bool bStartingPositionInitialized)
    {
        _startingPositionInitialized = bStartingPositionInitialized; 
    }

    // Overrides
    virtual void setPosition(const Vec2& position) override;
    virtual void setPosition(float x, float y) override;
    virtual const Vec2& getPosition() const override;
    virtual void getPosition(float* x, float* y) const override;
    virtual void setPositionX(float x) override;
    virtual void setPositionY(float y) override;
    virtual float getPositionX(void) const override;
    virtual float getPositionY(void) const override;
    virtual Vec3 getPosition3D() const override;
    /**
    * @js NA
    * @lua NA
    */
    virtual void draw(Renderer *renderer, const Mat4 &transform, unsigned int flags) override;
    /**
    * @lua NA
    */
    virtual void update(float delta) override;
    virtual Texture2D* getTexture() const override;
    virtual void setTexture(Texture2D *texture) override;
    /**
    * @js NA
    * @lua NA
    */
    virtual void setBlendFunc(const BlendFunc &blendFunc) override;
    /**
    * @js NA
    * @lua NA
    */
    virtual const BlendFunc& getBlendFunc() const override;
    virtual GLubyte getOpacity() const override;
    virtual void setOpacity(GLubyte opacity) override;
    virtual void setOpacityModifyRGB(bool value) override;
    virtual bool isOpacityModifyRGB() const override;
    
public:
    MotionStreak();
    virtual ~MotionStreak();
    
    /** initializes a motion streak with fade in seconds, minimum segments, stroke's width, color and texture filename */
    bool initWithFade(float fade, float minSeg, float stroke, const Color3B& color, const std::string& path);
    
    /** initializes a motion streak with fade in seconds, minimum segments, stroke's width, color and texture  */
    bool initWithFade(float fade, float minSeg, float stroke, const Color3B& color, Texture2D* texture);

protected:
    //renderer callback
    void onDraw(const Mat4 &transform, unsigned int flags);

    bool _fastMode;
    bool _startingPositionInitialized;

    /** texture used for the motion streak */
    Texture2D* _texture;
    BlendFunc _blendFunc;
    Vec2 _positionR;

    float _stroke;
    float _fadeDelta;
    float _minSeg;

    unsigned int _maxPoints;
    unsigned int _nuPoints;
    unsigned int _previousNuPoints;

    /** Pointers */
    Vec2* _pointVertexes;
    float* _pointState;

    // Opengl
    Vec2* _vertices;
    GLubyte* _colorPointer;
    Tex2F* _texCoords;
    
    CustomCommand _customCommand;

private:
    DISALLOW_COPY_AND_ASSIGN(MotionStreak);
};


#endif //__MOTION_STREAK_H__
