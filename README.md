# Maze-Creator

*  Maze Creator  v.1.3 -  by  rodrivas78  -  C++ / OpenGL / glut

   Useful to create mazes, complex terrains or intricated pathways and scenarios.
   It is not intended to generate 'standart' labyrinths (for that search for Prim's algorithm or Eller´s algorithm).
   When used with Photoshop (for post-processing the generated image, not as plug-in) becomes very good to create 
   natural/organic/fractured terrains or patterns (see example images). 

   Instructions: 
   When the execution starts, it generates an apparentely 'chaotic' image. Proceed with a "Print Screen" and 
   open it on Photoshop. Zoom in the image between 800 to 1000 times. Choose a region/sector 
   of the image (that you think has an interesting pattern) and cut it and save as RAW file
   (PRAW / 8BIM / No intercaleted order) and open it as  a 'highmap' in your favorite 3D modeling 
   software or game engine (Unity, Unreal Engine etc.).  

   Tips:
   To achieve a more organic or natural result, apply (artistic) filters in Photoshop.
   For variations you can tweak some variables: 'zoom', 'w', 'yF', 'xF' and 'z' (see optional formulas below).
   z=x1+y1  [or] z=(x1-y1+c1)+(2*x*y+c2)  [or]  z=(x*x+y*y)+(c1+c2)  
   yF=yF=(2*x^2)*y+c2   [or]   yF=2*x*y+c2  
   ->>Do not forget to resize the image to the same size of the terrain before creating the RAW file<<-
   
   Any problem, critics or suggestions, please contact me.
   
   For more information, see:
   ecosplatonicos.blogspot.com
