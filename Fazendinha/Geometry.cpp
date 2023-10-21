/**********************************************************************************
// Geometry (C�digo Fonte)
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

#include <cmath>
#include "Geometry.h"

// --------------------------------------------------------------------------
// Geometry
// --------------------------------------------------------------------------

Geometry::Geometry()
{ 
    x = y = 0.0f;
    scale = 1.0f;
    rotation = 0.0f;
    type = UNKNOWN_T; 
}
                                    
// --------------------------------------------------------------------------
    
Geometry::~Geometry()
{
}                


// --------------------------------------------------------------------------
// Point
// --------------------------------------------------------------------------

Point::Point()
{
    type = POINT_T;
}

// --------------------------------------------------------------------------

Point::Point(float posX, float posY)
{
    MoveTo(posX, posY);
    type = POINT_T;
}

// --------------------------------------------------------------------------

Point::Point(int posX, int posY)
{
    MoveTo(float(posX), float(posY)); 
    type = POINT_T;
}

// --------------------------------------------------------------------------

float Point::Distance(const Point& pa, const Point& pb)
{
    // os deltas podem resultar em valores negativos 
    // para evitar isso pega-se os valores absolutos
    float deltaX = abs(pb.x - pa.x);
    float deltaY = abs(pb.y - pa.y);

    // calcula e retorna a dist�ncia
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

// --------------------------------------------------------------------------
// Line
// --------------------------------------------------------------------------

Line::Line()
{
    // linha padr�o vai de (0,0) at� (0,0)
    a = Point();
    b = Point();
    type = LINE_T;
}

// --------------------------------------------------------------------------

Line::Line(float x1, float y1, float x2, float y2)
{
    // cria linha de (x1,y1) at� (x2,y2)
    a = Point(x1,y1);    
    b = Point(x2,y2);
    type = LINE_T;
}

// --------------------------------------------------------------------------
    
Line::Line(Point& pa, Point& pb)
{
    // cria linha de pa at� pb
    a = pa;
    b = pb;
    type = LINE_T;
}

// --------------------------------------------------------------------------

void Line::Rotate(float angle)
{
    // TODO: n�o fazer a rota��o aqui, mas apenas na hora de desenhar
    // de forma a conservar as coordenadas originais do objeto

    float xr, yr, theta;
    const double PIdiv180 = 0.0174532925194444;

    // converte �ngulo em radianos
    theta = float(angle * PIdiv180);

    // rotaciona cada ponto em rela��o a origem
    xr = a.X() * cos(theta) - a.Y() * sin(theta);
    yr = a.X() * sin(theta) + a.Y() * cos(theta);
    a.MoveTo(xr, yr);

    xr = b.X() * cos(theta) - b.Y() * sin(theta);
    yr = b.X() * sin(theta) + b.Y() * cos(theta);
    b.MoveTo(xr, yr);
}

// --------------------------------------------------------------------------

float Line::Angle(const Point& pa, const Point& pb)
{
    const double PI = 3.1415926535;

    // obt�m vetor que vai do ponto (pa) at� (pb)
    float dx, dy;
    float ang;

    // o c�lculo do "dy" � invertido porque nas coordenadas da tela
    // o eixo y � para baixo e no plano cartesiano ele � para cima
    dx = pb.X() - pa.X();
    dy = pa.Y() - pb.Y();

    // ajusta o �ngulo de acordo com o quadrante do vetor resultante
    if (dx > 0)
    {
        // 1o Quadrante
        if (dy >= 0)
        {
            // acha o �ngulo em radianos
            ang = atan(dy / dx);
            // converte de radianos para graus
            ang = float((180.0 * ang) / PI);
        }
        // 4o Quadrante
        else // (ry < 0)
        {
            // acha o �ngulo em radianos
            ang = atan(dy / dx);
            // converte de radianos para graus
            ang = float((180.0 * ang) / PI) + 360.0f;
        }
    }
    // 2o e 3o Quadrante
    else if (dx < 0)
    {
        // acha o �ngulo em radianos
        ang = atan(dy / dx);
        // converte de radianos para graus
        ang = float((180.0 * ang) / PI) + 180.0f;
    }
    else // (rx == 0)
    {
        if (dy > 0)
            ang = 90.0f;
        else if (dy < 0)
            ang = 270.0f;
        else
            ang = 0.0f;
    }

    return ang;
}

// --------------------------------------------------------------------------
// Rect  
// --------------------------------------------------------------------------

Rect::Rect()
{
    // cria ret�ngulo de (0,0) at� (0,0)
    left = right  = 0.0f;
    top  = bottom = 0.0f;
    type = RECTANGLE_T;
}

// --------------------------------------------------------------------------

Rect::Rect(float x1, float y1, float x2, float y2)
{
    // cria ret�ngulo
    left   = x1;
    top    = y1;
    right  = x2; 
    bottom = y2;
    type   = RECTANGLE_T;
}

// --------------------------------------------------------------------------
Rect::Rect(Point& a, Point& b)
{
    // cria ret�ngulo
    left   = a.X();
    top    = a.Y();
    right  = b.X(); 
    bottom = b.Y();
    type   = RECTANGLE_T;
}

// --------------------------------------------------------------------------
// Circle  
// --------------------------------------------------------------------------

Circle::Circle()
{
    // c�rculo padr�o tem raio nulo
    radius   = 0;
    type     = CIRCLE_T;
}

// --------------------------------------------------------------------------

Circle::Circle(float r)
{
    // define c�rculo de raio r
    radius   = r;
    type     = CIRCLE_T;
}

// --------------------------------------------------------------------------
// Poly 
// --------------------------------------------------------------------------

Poly::Poly()
{
    vertexCount = 0;            // pol�gono n�o tem v�rtices
    vertexList  = nullptr;      // inicialmente a lista de v�rtices � vazia
    bbox = new Circle();        // bounding box padr�o � um c�rculo
    type = POLYGON_T;           // tipo pol�gono
}

// --------------------------------------------------------------------------

Poly::Poly(Point * vList, uint vCount)
{
    // guarda n�mero de v�rtices do pol�gono
    vertexCount = vCount;                    
    
    // aloca mem�ria para os v�rtices
    vertexList = new Point[vCount];    

    // guarda lista de v�rtices do pol�gono
    for (uint i=0; i < vCount; ++i)        
        vertexList[i].MoveTo(vList[i].X(), vList[i].Y());

    // calcula bounding box deste pol�gono
    BuildBBox();

    // tipo pol�gono
    type = POLYGON_T;
}

// --------------------------------------------------------------------------

Poly::Poly(const Poly& p)
{
    // guarda n�mero de v�rtices do pol�gono
    vertexCount = p.vertexCount;                    
    
    // aloca mem�ria para os v�rtices
    vertexList = new Point[vertexCount];    

    // guarda lista de v�rtices do pol�gono
    for (uint i=0; i < vertexCount; ++i)
        vertexList[i].MoveTo(p.vertexList[i].X(), p.vertexList[i].Y());

    // calcula bounding box deste pol�gono
    BuildBBox();

    // tipo pol�gono
    type = POLYGON_T;
}

// --------------------------------------------------------------------------

const Poly& Poly::operator=(const Poly& p)
{
    // libera mem�ria alocada por v�rtices antigos, se existirem
    if (vertexList)
        delete [] vertexList;

    // guarda n�mero de v�rtices do pol�gono
    vertexCount = p.vertexCount;                    
    
    // aloca mem�ria para os v�rtices
    vertexList = new Point[vertexCount];    

    // guarda lista de v�rtices do pol�gono
    for (uint i=0; i < vertexCount; ++i)
        vertexList[i].MoveTo(p.vertexList[i].X(), p.vertexList[i].Y());
    // calcula bounding box deste pol�gono
    BuildBBox();

    // tipo pol�gono
    type = POLYGON_T;

    return *this;
}

// --------------------------------------------------------------------------

void Poly::Translate(float dx, float dy)
{
    x += dx; 
    y += dy;
    bbox->Translate(dx, dy);
}

// --------------------------------------------------------------------------

void Poly::MoveTo(float px, float py)
{
    x = px;
    y = py;
    bbox->MoveTo(px, py);
}

// --------------------------------------------------------------------------

float Poly::Scale() const
{
    return scale;
}

// --------------------------------------------------------------------------

void Poly::Scale(float factor)
{
    scale *= factor;
    bbox->Scale(factor);
}

// --------------------------------------------------------------------------

void Poly::ScaleTo(float value)
{
    scale = value;
    bbox->ScaleTo(value);
}

// --------------------------------------------------------------------------

void Poly::BuildBBox()
{
    float curRadius;
    float maxRadius = 0.0f;

    // acha a maior dist�ncia para o centro do pol�gono
    for (uint i = 0; i < vertexCount; ++i)
    {
        // aplica fator de escala
        float pX = vertexList[i].X() * scale;
        float pY = vertexList[i].Y() * scale;

        // calcula o raio de cada v�rtice do pol�gono
        curRadius = Point::Distance(Point(pX,pY), Point(0,0));
        if (maxRadius < curRadius)
            maxRadius = curRadius;
    }

    // a bounding box � um c�rculo que engloba o pol�gono
    if (bbox) delete bbox;
    bbox = new Circle(maxRadius);
    bbox->MoveTo(x, y);
}

// --------------------------------------------------------------------------

Poly::~Poly()
{
    // libera mem�ria alocada para os v�rtices
    if (vertexList)
        delete [] vertexList;
}


// --------------------------------------------------------------------------
// Mixed 
// --------------------------------------------------------------------------

Mixed::Mixed()
{
    type = MIXED_T;
}

// --------------------------------------------------------------------------

Mixed::~Mixed()
{
    // libera a mem�ria ocupa pelas geometrias que comp�em essa forma mista
    for (auto i : shapes)
        delete i;
}

// --------------------------------------------------------------------------

void Mixed::Insert(Geometry * s)
{
    shapes.push_back(s);
}

// --------------------------------------------------------------------------

void Mixed::Remove(Geometry * s)
{
    auto i = find(shapes.begin(), shapes.end(), s);
    shapes.erase(i);
}

// --------------------------------------------------------------------------

void Mixed::Translate(float dx, float dy)
{
    x += dx;
    y += dy;

    for (auto i : shapes)
        i->Translate(dx, dy);
}

// --------------------------------------------------------------------------

void Mixed::MoveTo(float px, float py)
{
    for (auto i : shapes)
    {
        float deltaX = i->X() - x;
        float deltaY = i->Y() - y;
        i->MoveTo(px + deltaX, py + deltaY);
    }

    x = px;
    y = py;
}

// --------------------------------------------------------------------------

float Mixed::Scale() const
{
    return scale;
}

// --------------------------------------------------------------------------

void Mixed::Scale(float factor)
{
    scale *= factor;

    for (auto i : shapes)
        i->Scale(factor);
}

// --------------------------------------------------------------------------

void Mixed::ScaleTo(float value)
{
    scale = value;
    for (auto i : shapes)
        i->ScaleTo(value);
}

// --------------------------------------------------------------------------
