class AstronomicalBody {
  float x, y, diameter, angle;
}

AstronomicalBody sun = new AstronomicalBody();
AstronomicalBody earth = new AstronomicalBody();
AstronomicalBody moon = new AstronomicalBody();

void setup()
{
  size(600, 600);

  sun.x = width/2;
  sun.y = height/2;
  sun.diameter = min(height, width)/8;

  earth.diameter = sun.diameter/5;

  moon.diameter = earth.diameter/3;
  moon.angle = PI/2;
}

void draw()
{
  background(200);

  float distanciaSolTerra = sun.diameter * 3;
  float distanciaTerraLua = earth.diameter * 2;

  // sun
  ellipse(sun.x, sun.y, sun.diameter, sun.diameter);

  // earth
  earth.x = sun.x + distanciaSolTerra * cos(earth.angle);
  earth.y = sun.y + distanciaSolTerra * sin(earth.angle);
  ellipse(earth.x, earth.y, earth.diameter, earth.diameter);

  // moon
  moon.x = earth.x + distanciaTerraLua * cos(moon.angle);
  moon.y = earth.y + distanciaTerraLua * sin(moon.angle);
  ellipse(moon.x, moon.y, moon.diameter, moon.diameter);

  earth.angle += .02;
  moon.angle += .04;
}
