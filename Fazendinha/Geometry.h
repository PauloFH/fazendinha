/**********************************************************************************
// Geometry (Arquivo de Cabe�alho)
//
// Cria��o:     05 Oct 2007
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2022
//
// Descri��o:   Agrupa a defini��o de todas as formas geom�tricas suportadas:
//              ponto, linha, ret�ngulo, c�rculo, pol�gono e mista (agrupamento
//              de uma ou mais geometrias)
//
**********************************************************************************/

#ifndef _PROGJOGOS_GEOMETRY_H_
#define _PROGJOGOS_GEOMETRY_H_

#include "Types.h"                                      // tipos da engine
#include <list>                                         // lista da STL
using std::list;                                        // usar list sem std::

// ---------------------------------------------------------------------------

enum GeometryTypes
{
    UNKNOWN_T,                                          // desconhecido
    POINT_T,                                            // ponto
    LINE_T,                                             // linha
    RECTANGLE_T,                                        // ret�ngulo
    CIRCLE_T,                                           // c�rculo
    POLYGON_T,                                          // pol�gono
    MIXED_T                                             // mista
};

// ---------------------------------------------------------------------------
// Geometry
// ---------------------------------------------------------------------------

class Geometry
{
protected:
    float x, y;                                         // posi��o da geometria
    float scale;                                        // escala da geometria
    float rotation;                                     // rota��o da geometria
    uint type;                                          // tipo da geometria

public:
    Geometry();                                         // construtor
    virtual ~Geometry();                                // destrutor

    virtual float X() const                             // retorna coordenada x
    { return x; }            
    
    virtual float Y() const                             // retorna coordenada y
    { return y; }    
    
    virtual float Scale() const                         // retorna escala
    { return scale; }

    virtual float Rotation() const                      // retorna rota��o
    { return rotation; }

    virtual uint Type() const                           // retorna tipo 
    { return type; }        
    
    virtual void Translate(float dx, float dy)          // move a geometria por (dx,dy)
    { x += dx; y += dy; }

    virtual void MoveTo(float px, float py)             // move a geometria para a posi��o (px,py)
    { x = px; y = py; }

    virtual void Scale(float factor)                    // amplia ou reduz a geometria por um fator
    { scale *= factor; }

    virtual void ScaleTo(float value)                   // ajusta escala para novo valor
    { scale = value; }

    virtual void Rotate(float angle)                    // rotaciona geometria por um �ngulo
    { rotation += angle; }

    virtual void RotateTo(float value)                  // ajusta ota��o para novo valor
    { rotation = value; }
};

// --------------------------------------------------------------------------
// Point
// --------------------------------------------------------------------------

class Point : public Geometry
{
public:
    Point();                                            // construtor padr�o
    Point(float posX, float posY);                      // construtor usando pontos-flutuantes
    Point(int posX, int posY);                          // construtor usando inteiros
    
    // retorna a dist�ncia entre os pontos
    static float Distance(const Point& pa, const Point& pb);              
};

// --------------------------------------------------------------------------
// Line
// -------------------------------------------------------------------------

class Line : public Geometry
{
public:
    Point a, b;                                         // linha vai do ponto A ao ponto B
    
    Line();                                             // construtor padr�o
    Line(float x1, float y1, float x2, float y2);       // construtor usando pontos-flutuantes
    Line(Point& pa, Point& pb);                         // construtor usando pontos

    void Rotate(float angle);                           // rotaciona linha por um �ngulo

    float Ax() const { return x + (a.X() * scale); }    // coordenadas do mundo do ponto A eixo x
    float Ay() const { return y + (a.Y() * scale); }    // coordenadas do mundo do ponto A eixo y
    float Bx() const { return x + (b.X() * scale); }    // coordenadas do mundo do ponto B eixo x
    float By() const { return y + (b.Y() * scale); }    // coordenadas do mundo do ponto B eixo y

    // retorna o �ngulo da linha formada pelos pontos
    static float Angle(const Point& pa, const Point& pb);
};

// --------------------------------------------------------------------------
// Rect
// --------------------------------------------------------------------------

class Rect : public Geometry
{
public:
    float left;                                         // coordenada esquerda do ret�ngulo
    float top;                                          // coordenada superior do ret�ngulo
    float right;                                        // coordenada direita do ret�ngulo
    float bottom;                                       // coordenada inferior do ret�ngulo

    Rect();                                             // construtor padr�o
    Rect(float x1, float y1, float x2, float y2);       // construtor usando pontos-flutuantes
    Rect(Point& a, Point& b);                           // construtor usando pontos

    float Left() const   { return x + (left*scale);   } // coordenadas do mundo do menor valor do eixo x
    float Top() const    { return y + (top*scale);    } // coordenadas do mundo do menor valor do eixo y
    float Right() const  { return x + (right*scale);  } // coordenadas do mundo do maior valor do eixo x
    float Bottom() const { return y + (bottom*scale); } // coordenadas do mundo do maior valor do eixo y
};

// --------------------------------------------------------------------------
// Circle
// --------------------------------------------------------------------------

class Circle : public Geometry
{
private:
    float radius;                                       // raio do c�rculo

public:
    Circle();                                           // construtor padr�o
    Circle(float r);                                    // contrutor com raio

    float Radius() const { return radius * scale; }     // tamanho do raio
    float CenterX() const { return x; }                 // coordenadas do mundo do centro (eixo x)
    float CenterY() const { return y; }                 // coordenadas do mundo do centro (eixo y)
};

// --------------------------------------------------------------------------
// Poly
// --------------------------------------------------------------------------

class Poly : public Geometry
{
private:
    Circle * bbox;                                      // bounding box do pol�gono
    void     BuildBBox();                               // cria a bounding box do pol�gono

public:
    uint      vertexCount;                              // n�mero de v�rtices 
    Point*    vertexList;                               // vetor de v�rtices do pol�gono

    Poly();                                             // construtor padr�o
    Poly(Point * vList, uint vCount);                   // construtor
    Poly(const Poly& p);                                // construtor de c�pia
    ~Poly();                                            // destructor

    const Poly& operator=(const Poly& p);               // operador de atribui��o

    void Translate(float dx, float dy);                 // move pol�gono por (dx,dy)
    void MoveTo(float px, float py);                    // move pl�gono para a posi��o (px,py)
    void Scale(float factor);                           // amplia ou reduz geometria por um fator
    void ScaleTo(float factor);                         // ajusta a escala para novo valor

    float Scale() const;                                // retorna escala do pol�gono    
    Circle * BBox() const { return bbox; }              // retorna bounding box do pol�gono
}; 

// --------------------------------------------------------------------------
// Mixed
// --------------------------------------------------------------------------

class Mixed : public Geometry
{
public:
    list<Geometry*> shapes;                             // lista de formas geom�tricas
    
    Mixed();                                            // construtor padr�o
    ~Mixed();                                           // destructor

    void Insert(Geometry * s);                          // insere geometria na lista
    void Remove(Geometry * s);                          // remove geometria da lista

    void Translate(float dx, float dy);                 // move a geometria pelo delta (dx,dy)
    void MoveTo(float px, float py);                    // move a geometria para a posi��o (px,py)
    void Scale(float factor);                           // altera escala da geometria    
    void ScaleTo(float factor);                         // ajusta a escala para novo valor

    float Scale() const;                                // retorna escala da geometria
};

// --------------------------------------------------------------------------

#endif
