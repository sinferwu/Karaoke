#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__

#include <string>

#include "Math/Geometry.h"
#include "Math/Math.h"
#include "Renderer/OpenGLESHeaders.h"

struct Color4B;
struct Color4F;

/**
 * RGB color composed of bytes 3 bytes.
 * @since v3.0
 */
struct  Color3B
{
    Color3B();
    Color3B(GLubyte _r, GLubyte _g, GLubyte _b);
    explicit Color3B(const Color4B& color);
    explicit Color3B(const Color4F& color);

    bool operator==(const Color3B& right) const;
    bool operator==(const Color4B& right) const;
    bool operator==(const Color4F& right) const;
    bool operator!=(const Color3B& right) const;
    bool operator!=(const Color4B& right) const;
    bool operator!=(const Color4F& right) const;

    bool equals(const Color3B& other)
    {
        return (*this == other);
    }

    GLubyte r;
    GLubyte g;
    GLubyte b;

    static const Color3B WHITE;
    static const Color3B YELLOW;
    static const Color3B BLUE;
    static const Color3B GREEN;
    static const Color3B RED;
    static const Color3B MAGENTA;
    static const Color3B BLACK;
    static const Color3B ORANGE;
    static const Color3B GRAY;
};

/**
 * RGBA color composed of 4 bytes.
 * @since v3.0
 */
struct  Color4B
{
    Color4B();
    Color4B(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a);
    explicit Color4B(const Color3B& color);
    explicit Color4B(const Color4F& color);
    
    inline void set(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    bool operator==(const Color4B& right) const;
    bool operator==(const Color3B& right) const;
    bool operator==(const Color4F& right) const;
    bool operator!=(const Color4B& right) const;
    bool operator!=(const Color3B& right) const;
    bool operator!=(const Color4F& right) const;

    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;

    static const Color4B WHITE;
    static const Color4B YELLOW;
    static const Color4B BLUE;
    static const Color4B GREEN;
    static const Color4B RED;
    static const Color4B MAGENTA;
    static const Color4B BLACK;
    static const Color4B ORANGE;
    static const Color4B GRAY;
};


/**
 * RGBA color composed of 4 floats.
 * @since v3.0
 */
struct  Color4F
{
    Color4F();
    Color4F(float _r, float _g, float _b, float _a);
    explicit Color4F(const Color3B& color);
    explicit Color4F(const Color4B& color);

    bool operator==(const Color4F& right) const;
    bool operator==(const Color3B& right) const;
    bool operator==(const Color4B& right) const;
    bool operator!=(const Color4F& right) const;
    bool operator!=(const Color3B& right) const;
    bool operator!=(const Color4B& right) const;

    bool equals(const Color4F &other)
    {
        return (*this == other);
    }

    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;

    static const Color4F WHITE;
    static const Color4F YELLOW;
    static const Color4F BLUE;
    static const Color4F GREEN;
    static const Color4F RED;
    static const Color4F MAGENTA;
    static const Color4F BLACK;
    static const Color4F ORANGE;
    static const Color4F GRAY;
};

/** A vertex composed of 2 floats: x, y
 @since v3.0
 */
// struct Vertex2F
// {
//     Vertex2F(float _x, float _y) :x(_x), y(_y) {}

//     Vertex2F(): x(0.f), y(0.f) {}

//     GLfloat x;
//     GLfloat y;
// };


/** A vertex composed of 2 floats: x, y
 @since v3.0
 */
// struct Vertex3F
// {
//     Vertex3F(float _x, float _y, float _z)
//         : x(_x)
//         , y(_y)
//         , z(_z)
//     {}

//     Vertex3F(): x(0.f), y(0.f), z(0.f) {}

//     GLfloat x;
//     GLfloat y;
//     GLfloat z;
// };

/** @struct Tex2F
 * A TEXCOORD composed of 2 floats: u, y
 * @since v3.0
 */
struct  Tex2F {
    Tex2F(float _u, float _v): u(_u), v(_v) {}

    Tex2F(): u(0.f), v(0.f) {}

    GLfloat u;
    GLfloat v;
};

/** @struct PointSprite
 * Vec2 Sprite component.
 */
struct  PointSprite
{
    Vec2   pos;        // 8 bytes
    Color4B    color;      // 4 bytes
    GLfloat    size;       // 4 bytes
};

/** @struct Quad2
 * A 2D Quad. 4 * 2 floats.
 */
struct  Quad2
{
    Vec2        tl;
    Vec2        tr;
    Vec2        bl;
    Vec2        br;
};

/** @struct Quad3
 * A 3D Quad. 4 * 3 floats.
 */
struct  Quad3 {
    Vec3        bl;
    Vec3        br;
    Vec3        tl;
    Vec3        tr;
};

/** @struct V2F_C4B_T2F
 * A Vec2 with a vertex point, a tex coord point and a color 4B.
 */
struct V2F_C4B_T2F
{
    /// vertices (2F)
    Vec2       vertices;
    /// colors (4B)
    Color4B        colors;
    /// tex coords (2F)
    Tex2F          texCoords;
};

/** @struct V2F_C4B_PF
 *
 */
struct V2F_C4B_PF
{
    /// vertices (2F)
    Vec2       vertices;
    /// colors (4B)
    Color4B        colors;
    /// pointsize
    float      pointSize;
};

/** @struct V2F_C4F_T2F
 * A Vec2 with a vertex point, a tex coord point and a color 4F.
 */
struct  V2F_C4F_T2F
{
    /// vertices (2F)
    Vec2       vertices;
    /// colors (4F)
    Color4F        colors;
    /// tex coords (2F)
    Tex2F          texCoords;
};

/** @struct V3F_C4B_T2F
 * A Vec2 with a vertex point, a tex coord point and a color 4B.
 */
struct  V3F_C4B_T2F
{
    /// vertices (3F)
    Vec3     vertices;            // 12 bytes

    /// colors (4B)
    Color4B      colors;              // 4 bytes

    // tex coords (2F)
    Tex2F        texCoords;           // 8 bytes
};

/** @struct V3F_T2F
 * A Vec2 with a vertex point, a tex coord point.
 */
struct  V3F_T2F
{
    /// vertices (2F)
    Vec3       vertices;
    /// tex coords (2F)
    Tex2F          texCoords;
};

/** @struct V2F_C4B_T2F_Triangle
 * A Triangle of V2F_C4B_T2F.
 */
struct  V2F_C4B_T2F_Triangle
{
	V2F_C4B_T2F a;
	V2F_C4B_T2F b;
	V2F_C4B_T2F c;
};

/** @struct V2F_C4B_T2F_Quad
 * A Quad of V2F_C4B_T2F.
 */
struct  V2F_C4B_T2F_Quad
{
    /// bottom left
    V2F_C4B_T2F    bl;
    /// bottom right
    V2F_C4B_T2F    br;
    /// top left
    V2F_C4B_T2F    tl;
    /// top right
    V2F_C4B_T2F    tr;
};

/** @struct V3F_C4B_T2F_Quad
 * 4 Vertex3FTex2FColor4B.
 */
struct  V3F_C4B_T2F_Quad
{
    /// top left
    V3F_C4B_T2F    tl;
    /// bottom left
    V3F_C4B_T2F    bl;
    /// top right
    V3F_C4B_T2F    tr;
    /// bottom right
    V3F_C4B_T2F    br;
};

/** @struct V2F_C4F_T2F_Quad
 * 4 Vertex2FTex2FColor4F Quad.
 */
struct  V2F_C4F_T2F_Quad
{
    /// bottom left
    V2F_C4F_T2F    bl;
    /// bottom right
    V2F_C4F_T2F    br;
    /// top left
    V2F_C4F_T2F    tl;
    /// top right
    V2F_C4F_T2F    tr;
};

/** @struct V3F_T2F_Quad
 *
 */
struct  V3F_T2F_Quad
{
    /// bottom left
    V3F_T2F    bl;
    /// bottom right
    V3F_T2F    br;
    /// top left
    V3F_T2F    tl;
    /// top right
    V3F_T2F    tr;
};

/** @struct BlendFunc
 * Blend Function used for textures.
 */
struct  BlendFunc
{
    /** source blend function */
    GLenum src;
    /** destination blend function */
    GLenum dst;

    /** Blending disabled. Uses {GL_ONE, GL_ZERO} */
    static const BlendFunc DISABLE;
    /** Blending enabled for textures with Alpha premultiplied. Uses {GL_ONE, GL_ONE_MINUS_SRC_ALPHA} */
    static const BlendFunc ALPHA_PREMULTIPLIED;
    /** Blending enabled for textures with Alpha NON premultiplied. Uses {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA} */
    static const BlendFunc ALPHA_NON_PREMULTIPLIED;
    /** Enables Additive blending. Uses {GL_SRC_ALPHA, GL_ONE} */
    static const BlendFunc ADDITIVE;

    bool operator==(const BlendFunc &a) const
    {
        return src == a.src && dst == a.dst;
    }

    bool operator!=(const BlendFunc &a) const
    {
        return src != a.src || dst != a.dst;
    }

    bool operator<(const BlendFunc &a) const
    {
        return src < a.src || (src == a.src && dst < a.dst);
    }
};

/** @struct TextVAlignment
 * Vertical text alignment type.
 *
 * @note If any of these enums are edited and/or reordered, update Texture2D.m.
 */
enum TextVAlignment
{
    V_TOP,
    V_CENTER,
    V_BOTTOM
};

/** @struct TextHAlignment
 * Horizontal text alignment type.
 *
 * @note If any of these enums are edited and/or reordered, update Texture2D.m.
 */
enum TextHAlignment
{
    H_LEFT,
    H_CENTER,
    H_RIGHT
};

/**
* @brief Possible GlyphCollection used by Label.
*
* Specify a collections of characters to be load when Label created.
* Consider using DYNAMIC.
*/
enum GlyphCollection {
    DYNAMIC,
    NEHE,
    ASCII,
    CUSTOM
};

// Types for animation in particle systems

/** @struct T2F_Quad
 * Texture coordinates for a quad.
 */
struct  T2F_Quad
{
    /// bottom left
    Tex2F    bl;
    /// bottom right
    Tex2F    br;
    /// top left
    Tex2F    tl;
    /// top right
    Tex2F    tr;
};

/** @struct AnimationFrameData
 * Struct that holds the size in pixels, texture coordinates and delays for animated ParticleSystemQuad.
 */
struct  AnimationFrameData
{
    T2F_Quad texCoords;
    float delay;
    Size size;
};

/**
 types used for defining fonts properties (i.e. font name, size, stroke or shadow)
 */

/** @struct FontShadow
 * Shadow attributes.
 */
struct  FontShadow
{
public:

    // shadow is not enabled by default
    FontShadow()
        : _shadowEnabled(false)
        , _shadowBlur(0)
        , _shadowOpacity(0)
    {}

    /// true if shadow enabled
    bool   _shadowEnabled;
    /// shadow x and y offset
	Size   _shadowOffset;
    /// shadow blurrines
	float  _shadowBlur;
    /// shadow opacity
	float  _shadowOpacity;
};

/** @struct FontStroke
 * Stroke attributes.
 */
struct  FontStroke
{
public:

    // stroke is disabled by default
    FontStroke()
	    : _strokeEnabled(false)
        , _strokeColor(Color3B::BLACK)
        , _strokeAlpha(255)
        , _strokeSize(0)
    {}

    /// true if stroke enabled
    bool      _strokeEnabled;
    /// stroke color
	Color3B   _strokeColor;
    /// stroke alpha
    GLubyte   _strokeAlpha;
    /// stroke size
    float     _strokeSize;

};

/** @struct FontDefinition
 * Font attributes.
 */
struct  FontDefinition
{
public:
    /**
     * @js NA
     * @lua NA
     */
    FontDefinition()
        : _fontSize(0)
        , _alignment(TextHAlignment::H_CENTER)
        , _vertAlignment(TextVAlignment::V_TOP)
    	, _dimensions(Size::ZERO)
        , _fontFillColor(Color3B::WHITE)
        , _fontAlpha(255)
    {}

    /// font name
    std::string           _fontName;
    /// font size
    int                   _fontSize;
    /// horizontal alignment
    TextHAlignment        _alignment;
    /// vertical alignment
    TextVAlignment _vertAlignment;
    /// renering box
    Size                  _dimensions;
    /// font color
    Color3B               _fontFillColor;
    /// font alpha
    GLubyte               _fontAlpha;
    /// font shadow
    FontShadow            _shadow;
    /// font stroke
    FontStroke            _stroke;

};

/**
 * @brief Possible LabelEffect used by Label.
 *
 */
enum LabelEffect {
    NORMAL,
    OUTLINE,
    SHADOW,
    GLOW,
    ALL
};

/** @struct Acceleration
 * The device accelerometer reports values for each axis in units of g-force.
 */
class  Acceleration
{
public:
    double x;
    double y;
    double z;

    double timestamp;

    Acceleration(): x(0), y(0), z(0), timestamp(0) {}
};

extern const long INVALID_INDEX;

#endif //__BASE_TYPES_H__