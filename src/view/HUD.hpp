#ifndef _HUD_H
#define _HUD_H

#include <QBrush>
#include <QFont>
#include <QImage>
#include <QPen>
#include <QGLWidget>
#include <QString>
#include <string.h>
#include <QFontMetrics>
#include "math/glVector.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream> 

class HUD{
public:
  /**
   * @brief Draws the HUD
   * @param painter Used QPainter
   * @param x width of the window;
   * @param y hiegth of the window;
   * @param f Used Font
   */
  void draw(QPainter *paint,int x ,int y, QFont f);
    
  /**
   *@brief Draws the given Astroid on the rada
   *@param painter used QPainter
   *@param radarraange the max distance for astroids
   *@param durchmesser diameter of the radar
   *@param radarmidx x value of the radarmid
   *@param radarmidy y value of the radarmid
   *@param QPainter used QPainter
   */
  void drawRadarAstroid(glVector<float>* vec, int radarrange, int durchmesser, int radarmidx, int radarmidy,QPainter *paint);

  /**
   *@brief sets the collvec which contains the astroids in Radarrange
   *@param vector vector with astroids in radarrange
   */
  void setAstroidsVector(std::vector<glVector<float>* > collvec);

  /**
  	*@brief paint the score
  	*@param points
  	*@param breite width
  	*@param used Qpainter
  	*/
  void score(int punkte, int breite, QPainter *painter);

  /**
  	*@brief paint the damage
  	*@param damage the actual damage
  	*@param breite width
  	*@param used Qpainter
  	*/
  void damages(int schaden, int breite, QPainter *painter);
	
	/**
	 *@brief Draws the speed
	 *@param int speed 
	 *@param breite width
	 *@param painter used Painter
	 */  
  void Speed(float speed, int breite, QPainter *painter);
  
	/**
	 *@briefset Method for fighter Data like Score,damage speed
	 *@param damage actual damage
	 *@param score actual score
	 *@param speed actual speed
	 */
	void setFighterData(int damage, int score, float speed);    
private:
    ///HUD();
    //HUD(const HUD&);
    //~HUD();
    //static HUD* instance;
  /*used QPainter*/

  QPainter *painter;
  float fighterSpeed;
  int fighterDamage;
  int fighterScore;
  /*vector which contains the astroids in radarrange*/
  std::vector<glVector<float>* > collvec;
    
};

#endif //_HUD_H
