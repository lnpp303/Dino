#include "dino.h"

using namespace std;

Dino::Dino()
{

    dino_x = DINO_X;
    dino_y = DINO_Y;

    collision = {getX(), getY(), 68, 77 };

    for (int i=0; i<RUN_FRAME; i++)
    {
        runClips[i] = {i*FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE};
    }
    for (int i=0; i<COUCH_FRAME; i++)
    {
        couchClips[i] = {(i+16)*FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE};
    }
}

Dino::~Dino()
{

}

bool Dino::loadFromFile(string path, SDL_Renderer* renderer)
{
    bool res = Texture::loadFromFile(path, renderer);
    return res;
}

void Dino::handleInput(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (ground)
            {
                y_val -=15;
                ground = false;

            }
            break;
        }

    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            if (!ground)
            {
                y_val += 5;
            }
            break;
        }
    }
}

void Dino::gravity()
{
    if (!ground)
    {
        y_val += GRAVITY;
        if (y_val>=MAX_GRAVITY)
        {
            y_val=MAX_GRAVITY;
        }
    }
    else y_val = GRAVITY;
}

bool Dino::checkCollision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB) {
		return false;
	}

	if (topA >= bottomB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}
	return true;


}
void Dino::update(vector <Obs*>& obsList)
{
    gravity();
    dino_y += y_val;

    collision.y = getY();

    for (int i=0; i<obsList.size(); i++)
    {

        if (checkCollision(collision, obsList.at(i)->getCollision()))
        {
            death = true;
            Mix_Chunk* collide = dino_sound.loadSound("collide.mp3");
            dino_sound.play(collide);
        }
    }
        if (dino_y>=390)
        {
            dino_y = 390;
            y_val = 0;
            ground = true;
        }



}
void Dino::render(SDL_Renderer* renderer)
{
    if (!couch && !death)
    {
        couch_cnt = 0;
        renderClip(dino_x, dino_y, renderer, &runClips[run_cnt]);
        run_cnt++;
        if (run_cnt >= RUN_FRAME)
        {
            run_cnt =0;
            score_num++;
        }
    }
    else if (!death)
    {
        run_cnt = 0;
        renderClip(dino_x, dino_y, renderer, &couchClips[couch_cnt]);
        couch_cnt++;
        if (couch_cnt >= COUCH_FRAME)
        {
            couch_cnt =0;
        }
    }

}




/*case SDLK_DOWN:
            couch =true;
            dino_y = 390;
            break;
case SDLK_DOWN:
            couch =true;
            dino_y = 390;
            break;
*/

