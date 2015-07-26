import ru.cleoag.*;

PS3Eye p;
PImage img;

int cameraWidth = 640;
int cameraHeight = 480;
int cameraRate = 60;

void setup(){
  size(640,480);
  p = new PS3Eye(this);
  p.start(cameraWidth,cameraHeight,cameraRate);
  img = createImage(cameraWidth,cameraHeight,RGB);
}
void draw(){
  background(0);
  p.update();
  p.imageCopy(img.pixels);
  img.updatePixels();
  image(img,0,0,width,height);
}

void stop(){
  p.stop();
}



