#include "view/HUD.hpp"

HUD::HUD(QPainter *paint)
{
	fighterDamage = 0;
	fighterSpeed  = 0;
	fighterScore  = 0;
	durchmesser   = 150;
	abstand       = 10;
	painter       = paint;
	paintLevel    = false;
}
void HUD::draw(int width, int height, QFont f)
{    
        radmidx = width/2;
        radmidy = height - (durchmesser/2) - abstand;
        
        if (paintLevel)
        	drawLevelEnd();
	    std::vector<glVector<float>* >::iterator itervec;
        itervec = collvec.begin();
        drawRadar(width,height);
        score(fighterScore,width/2);
        Speed(fighterSpeed,0);
        damages(fighterDamage,(width/2));
    	
        while(itervec != collvec.end())
        {
            drawRadarAstroid(*itervec, 5000, durchmesser, width /2, height -(durchmesser / 2) - abstand);	
            itervec++;
        }
     
}

void HUD::drawRadarAstroid(glVector<float>* vec, int radarrange, int durchmesser, int radarmidx, int radarmidy)
{
	    painter->setPen(QColor(0,255,0,255));
        int p = 6;
		glVector<float> tmp(*vec);
        tmp.x/=radarrange;
        tmp.y/=radarrange;
        tmp.z/=radarrange;
        tmp =/* (vec*(1/radarrange))*/tmp * (durchmesser/2);
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.z;

        if(tmp.z != 0)
            painter->drawLine(radarmidx+y,radarmidy+(x),radarmidx+y,radarmidy+x-z);
        painter->drawEllipse(radarmidx+y-(p/2), radarmidy+x-z-(p/2),p,p);
}

void HUD::setAstroidsVector(std::vector<glVector<float>* > collisionvec)
{
    collvec = collisionvec;
}

void HUD::score(int punkte, int breite)
{
	painter->setPen(QColor(255,255,255,255));
    std::ostringstream Str;

    std::string pkt;
	int a;
	int stelle = 9;
	int tmp;
	int array[]={0,0,0,0,0,0,0,0,0,0};
	while(punkte !=0)
	{
		tmp = punkte % 10;
		punkte /= 10;
		array[stelle--] += tmp;
		a = stelle + 1; 
		while(array[a] >= 10)
		{
			array[a] -= 10;
			array[--a]++;	
		} 
	}
	for(int i = 0; i < 10 ;i++)
	{
		   Str << array[i];
		   pkt= ""+Str.str();
		
	}
    pkt = "SCORE : "+pkt;
    QFont font("Helvetica", 20, QFont::Bold);
    painter->setFont(font);
    QString aktuellepunkte = QString::fromStdString(pkt);
    QPoint point = QPoint(breite/2,30);
    painter->drawText(point,aktuellepunkte);
}

void HUD::damages(int schaden, int breite)
{
    painter->setPen(QColor(0,255,0,255));
    
    if(schaden>30)
    { 
        painter->setPen(QColor(255,255,0,255));
    }
    if(schaden>75){
        painter->setPen(QColor(255,0,0,255));
    
    }
    
    std::ostringstream Str;
    Str << schaden;
    std::string dmg("Schaden:"+Str.str()+"%");
    QFont font("Helvetica", 20, QFont::Bold);
    painter->setFont(font);
    QString leben = QString::fromStdString(dmg);
    QPoint point = QPoint(breite+90,30);
    painter->drawText(point,leben);
}


void HUD::Speed(float speed, int breite)
{
    painter->setPen(QColor(255,255,255,255));
    std::ostringstream Str;
    Str << speed;
  	std::string spd("Speed:"+Str.str()+"%");
  	QFont font("Helvetica", 20, QFont::Bold);
  	painter->setFont(font);
  	QString qspeed = QString::fromStdString(spd);
  	QPoint point = QPoint(0,30);
  	painter->drawText(point,qspeed);	
}


void HUD::setFighterData(int damage, int score, float speed)
{
	fighterDamage = damage;
	fighterScore = score;
	fighterSpeed = speed;
}

void HUD::drawSplash(int breite, int hoehe)
{
	QImage myImage = QImage("res/images/splash.png");
	myImage.load("res/images/splash.png");
	QPoint point = QPoint(breite/2 - myImage.width()/2,hoehe/2 - myImage.height()/2);
	painter->drawImage(point, myImage);
	//TODO -- <-- Press any key -->
}
void HUD::drawRadar(int width, int height)
{
   painter->setPen(QColor(255,255,255,255));
   painter->drawEllipse(radmidx - durchmesser/2, radmidy - durchmesser/2,durchmesser,durchmesser);
   painter->drawEllipse(radmidx - durchmesser/4, radmidy - durchmesser/4,durchmesser/2,durchmesser/2);
        
   QRectF rectangle( (width/2)-(durchmesser/2), height-(durchmesser/2)-abstand-durchmesser/2, durchmesser, durchmesser);

   painter->drawPie(rectangle, 45*16, 90*16);
        
   QPoint point = QPoint(radmidx-15,radmidy-15);
   QImage myImage = QImage("res/images/ss.png");
   myImage.load("res/images/ss.png");
   painter->drawImage(point, myImage);	
}

void HUD::drawLevelEnd()
{
	std::cout << "Tim hat mist gemacht, auf henning :D" << levelNumber << std::endl;
	
	for(int i = 0 ; i < 10; i++)
	{
		std::cout << "ausgabe 1" << std::endl;
		painter->setPen(QColor(255,255,0,255));
		std::cout << "ausgabe 2" << std::endl;
	    std::ostringstream Str;
		
	    Str << levelNumber;
			std::cout << "hier" << std::endl;
	    QImage myImage = QImage("res/images/splash.png");
	    myImage.load("res/images/splash.png");
	    QPoint point = QPoint(100/2 - myImage.width()/2,100/2 - myImage.height()/2);
	    painter->drawImage(point, myImage);
	  	std::string spd("Level: " + Str.str());
	  	QFont font("Helvetica", 20, QFont::Bold);
	  	painter->setFont(font);
	  	QString qspeed = QString::fromStdString(spd);
	  	QPoint point2 = QPoint(100.0/2, 100.0/2);
	  	painter->drawText(point2,qspeed);

	  	sleep(100);
	}
	
}

void HUD::setIncLevel(bool shouldIPaint)
{
	paintLevel = shouldIPaint;
}

void HUD::setLevel(int levelnumber)
{
	levelNumber = levelnumber;
}
