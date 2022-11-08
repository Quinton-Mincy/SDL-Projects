# SDL-Projects

Download SDL Library: https://github.com/libsdl-org/SDL/releases/tag/release-2.24.1

SDL Documentation : https://www.libsdl.org/

## Moving Forward

After experimenting with the SDL library and SDL_ttf libraries, I have come to the conclusion that they are not the best tools for the job for this project (at least on there own), specifically for dynamically displaying characters on the screen. I plan to incorporate openGL (which is what SDL is actually built from) and freetype2. 




## Password Manager

### How It Looks So Far

##### The clouds will scroll infinitley across the screen to provide a screen saver to the application. The white box will eventually provide a text interface to enter a password, and retreive passwords that were saved previously.

![Screen Shot 2022-10-07 at 5 59 21 PM](https://user-images.githubusercontent.com/73136662/194668621-63a1cdc3-0dfc-473f-98c5-2ad33691d17f.png)

## User Input

##### The users keyboard entries and mouse inputs (the (x,y) coordinates of their mouse clicks relative to the origin of the SDL window) are currently being registered, but are not yet saved

![Screen Shot 2022-10-07 at 6 04 17 PM](https://user-images.githubusercontent.com/73136662/194669667-e43a75c8-1f42-45af-b6b6-6b588dff8f4b.png)
