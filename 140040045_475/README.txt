									2015-CS101		
GROUP NUMBER-475


NAMES			ROLL NUMBER

1.SAURABH SAMARIA	140040045  (LEADER)
2.AJAY GHUNAVAT   	140070025
3.ABHINAV DAWAS  	140040116
4.SUMIT ANAND		14D110025				  						
								  
			  _______________________________
			BUS RESERVATION SYSTEM			
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
INSTRUCTIONS TO SET UP THE SOFTWARE:

1.Software for the reservation system is quite simple and requires the user to have ubuntu installed in the machine.Along with ubuntu(14.02 LTS would be preferred) and windows you need to have code blocks 13.12 installed. Simplecpp library should also be installed.


	Now to setup code::blocks for simplecpp

		1) Open Code::Blocks

		2) Go to settings-Compiler

		3) Then to ToolChain Executables

		4) Change the following: 

		All the changes must be made by clicking on the ”...” buttons and navigating to the simplec/pp directory where s++ and makes++ is 
		located. Libsprite.a can be found inside the lib file(/home/user/simplecpp/lib).

		5) Then in the Additional Paths add the /home/<user>/simplecpp/

		6) Then go to the Search Directories tab. In compilers add /home/<user>/simplecpp and in linkers add /home/<user>/simplecpp/lib

		7) In linker settings add /home/<user>/simplecpp/lib/libsprite.a and in other linker options type in “-L /usr/X11R6/lib -lX11” without the quotes.

Now try out a sample program:

#include<simplecpp>

main_program

{

cout<<"hello word"<<endl;

}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Once you are done with this hectic procedure of installing simplecpp and all you can proceed to run the software.

youtube video link of our project " https://www.youtube.com/watch?v=nZybuAPsS6w&feature=youtube"


