## Current State Of The Project

All interaction with boxes is implemented.

## Issues at the moment

Currently I am trying to display a skybox.
The issue I have is that the application becomes very slow.
I think it's because I am loading textures in my game loop;
hence, I learned the hard way that memory access is 'expensive'.

That aside, my application runs fine on Linux/MacOS.
However, it seems to not have a framelimiter on a Windows PC.

