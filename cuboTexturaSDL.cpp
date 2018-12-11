#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

void desenhaCubo(float size) //funcao para desenhar o cubo
{
        float difamb[] = {1.0,0.5,0.3,1.0};
        glBegin(GL_QUADS);
                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb); //para iluminacao

                // front face
                glNormal3f(0.0,0.0,1.0); //vetor normal usado para calculo de iluminacao, em caso de uso desta funcao
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);

                // left face
                glNormal3f(-1.0,0.0,0.0);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);

                // back face
                glNormal3f(0.0,0.0,-1.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);

                // right face
                glNormal3f(1.0,0.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);

                // top face
                glNormal3f(0.0,1.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);

                // bottom face
                glNormal3f(0.0,-1.0,0.0);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
}

float angulo = 0.0;


unsigned int carregaTextura(const char* filename)
{
        SDL_Surface* img = SDL_LoadBMP(filename); //imagem.bmp passada como parametro para ser a textura, carrega na memoria
        unsigned int id; //identificador da textura
        glGenTextures(1, &id); //quantas texturas eu quero usar(poderia ser um conjunto de textura em um array), endereco na memoria desse identificador
        glBindTexture(GL_TEXTURE_2D, id); //tipo de textura , identificador
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels); //tipo de textura, nivel de textura, aonde guardar a imagem, largura, tamanho, borda, formato da imagem, tipo, array de pixel
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //minimo filtro
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //maximo filtro
        SDL_FreeSurface(img);
        return id;
}

unsigned int textura;

void init()
{
        glClearColor(0.0,0.0,0.0,1.0);  //cor de fundo
        glMatrixMode(GL_PROJECTION); //ajuste da tela
        glLoadIdentity(); //volta ao ajuste normal
        gluPerspective(45,640.0/480.0,1.0,500.0); //perspective, ver doc
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        textura = carregaTextura("imagem.bmp"); //diretorio
}

void display() //limpa a tela e desenha algo
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0,0.0,-5.0); //movimento translacao
        glRotatef(angulo,1.0,1.0,1.0); //movimento rotacao
        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
                glTexCoord2f(0.0,2.0);
                glVertex3f(-2.0,2.0,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(-2.0,-2.0,0.0);
                glTexCoord2f(2.0,0.0);
                glVertex3f(2.0,-2.0,0.0);
                glTexCoord2f(2.0,2.0);
                glVertex3f(2.0,2.0,0.0);
        glEnd();
}

int main(int argc, char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen;
        screen = SDL_SetVideoMode(1024, 768, 32, SDL_SWSURFACE|SDL_OPENGL|SDL_FULLSCREEN); //configuracao basica SDL
        bool running = true;
        const int FPS = 30;
        Uint32 start;
        SDL_Event event;
        init();
        while(running) {
                start = SDL_GetTicks();
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                                case SDLK_ESCAPE:
                                                        running = false;
                                                        break;
                                        }
                                        break;
                        }
                }

                display();
                SDL_GL_SwapBuffers(); //swap buffer para desenhar
                angulo += 0.5; //definindo valor do angulo que entrara na glRotate
                if(angulo > 360)
                        angulo -= 360;
                if(1000/FPS > SDL_GetTicks()-start)
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
        SDL_Quit();
        return 0;
}
