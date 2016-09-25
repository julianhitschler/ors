#ifndef VIDEO_UTILS_H_INCLUDED
#define VIDEO_UTILS_H_INCLUDED

SDL_Surface *load_image(std::string file_name);
void blit_surface(SDL_Surface* surface, SDL_Surface* background, int x, int y);

#endif // VIDEO_UTILS_H_INCLUDED
