### Wednesday, October 14
> __Summary:__
> * recreated the project and initiated a github repository for the project.  
> * created an initial sprite for the user.  
> * remade a developpment log for the project.  
> * configured a CMake file and a bash script to reduce time spent on getting the commands to test the project. 
> * created a shortened bash command `gen_proj` alongside an option to `-archive` the current build.
> 
> __Forecast:__
> * create a `Sprite_Array Load_Sprite(string codename)` which reads a tablefile to find the relative path to the Sprite and adds it to a `Sprite_Array`.  
> * create a `void Free_Sprite(Sprite sprite)` as a primitive to make `void Free_Sprite_Array(Sprite_Array sarray)`.
> * group all window and rendering loading functions into a single function `Initialize_GUI(GUI_t gui)` and create a `Terminate_GUI(GUI_t gui)`.
>
>__Notes:__
> * I made a new archive as of today to test the `gen_proj` function. It worked. 
> Which did come as a surprise to me since I thought I would face some bugs but for now it's handy as hell.
> * Making this is exciting.
> Usually I wouldn't have touched Cpp in advance nor Cmake, but now?
> Yeah, I'm casually asking an AI to make that bash. Ok yeah that does seem to drop the value but to be honest, I'm not gonna say no to a tool that gathers a bunch of useful functions all around the internet to grant me more ideas.
>
> end of notes.