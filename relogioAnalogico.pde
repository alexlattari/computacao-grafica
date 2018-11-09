void setup(){
  size(500,500);
  stroke(255);
  smooth();
  noFill();
}
void draw(){
  translate(width/2,height/2);
 
  strokeWeight(1);
  background(0);
  ellipse(0,0,500,500);//Creates de Watch circle
  
  //Draws clock numbers
  float rText = 220;
  textAlign(CENTER,CENTER);
  textSize(15);
  for(int i = 0; i < 12; i++){
      String texto = "" + i;
      if(i == 0){
           texto = "12";
      }
      float angulo = map(i,0,12,0,TWO_PI) - HALF_PI;
      text(texto,rText*cos(angulo),rText*sin(angulo));
  }
  
  //Draws the second hand
  float theta = map(second(),0,60,0,TWO_PI) - HALF_PI;
  line(0,0,cos(theta) * 150 , sin(theta) * 150); // draw the line
  
  //Draws the minute hand
  strokeWeight(2);
  theta = map(minute(),0,60,0,TWO_PI) - HALF_PI;
  line(0,0,cos(theta) * 150 , sin(theta) * 150); // draw the line
  
  //Draws the hour hand
  strokeWeight(4);
  //the hour function returns the time in 23 format so we need to convert to 12 format
  theta = map((hour() + minute()/60.0) ,0,24,0,2 * TWO_PI ) - HALF_PI;
  line(0,0,cos(theta) * 150 , sin(theta) * 150); // draw the line
}
