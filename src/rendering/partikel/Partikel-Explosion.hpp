
#ifndef _PARTIKEL_EXPLOSION_H
#define _PARTIKEL_EXPLOSION_H

#include "math/glVector.hpp"
#include <QtOpenGL>

// Partikel für Flug

class PartikelExplosion
{
public:
    //Konstruktor
    PartikelExplosion(glVector<float> pos, glVector<float> speed);
    //Desructor
    ~PartikelExplosion();
    // weitersetzen
    void update();
    
    bool isAlive();

    void render();
private:
    //Gesundheitstatus
    bool m_alive;
    //Lebensdauer
    float m_lifetime;
    //Startzeit
    float m_startlife;
    //aktuelle Position
    glVector<float> m_position;
    //grösse
    float m_size;

    float m_alpha;
    //Farbe
    glVector<float> m_color;

    glVector<float> m_speed;
       
    static GLuint tex;
};

#endif //_PARTIKEL_FLUG_H
