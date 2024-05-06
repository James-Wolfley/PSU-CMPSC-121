//Author    :   James P Wolfley
//Class     :   CMPSC 121
//Purpose   :	Displays a grid of random numbers using const values for the size.
//Sources of logic assistance: None

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    const int size = 50;
    int nums[size];
    int cols = 10;
    int rows = size / cols;
    srand(time(NULL));

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            //I did these both in the same loop because in this project it did not matter for function
            //All of these numbers are dirived from size so it will work no matter the value given to it
            //It would be trivial to just make a separate loop to fill the array first
            nums[i * 10 + j] = rand() % 10000 + 1;
            cout << fixed << setw(5) << nums[i * 10 + j];
        }
        cout << endl;
    }
    
}

/*
1941 5538  495 7820 3482 7745 2964 8853 8550 3905
 5096 3740  678 9706 7345 4946  142 2129 7268 7929
 3821  118 1370 6305 3379  127 7721 6415 3296 7349
 1824 9503 9278 3980 6610 9516 4097 3641  279 4461
 4158 8992 3919 3010   10 8748 6488 7663 1956  674

 1983 4195  585 2963 6500 3257  657 3567 3825 9516
 3174 4312 3572 5433  932  965 8328 2281 8299 8838
 1151 4762 9955 1959 9377 2819 2588 1223 2132  210
 8068 2137 3773  649 7725 2298 8054 7657 4270 3509
 6144 2509 1448  979 2843 8394 1804 8375 8579 9173
*/



//For fun this is some code I wrote when I was just getting started in 2014, crazy to think its been that long
//It was written in lua for a minecraft mod called computercraft and I beleive dug out a variable sized room
/*
tArgs = {...}
local length = tArgs[1]
local width = tArgs[2]
local switch = "right"
local chest = turtle.getItemCount(16)

os.loadAPI("turtleAPI")

if length == nil then
  length = 9
end

if width == nil then
  width = 9
end

if length == "help" then
  print("usage... room <length> <width>")
  print("if no length or width is given")
  print("they default to 9")
  return
end
turtleAPI.digForward()
turtleAPI.digUp()
turtle.digDown()
for i = 1,width do
  for j = 1,length - 1 do
    print(i .. "," .. j)
    turtleAPI.digForward()
    turtleAPI.digUp()
    turtle.digDown()
    while turtle.getItemCount(15) > 1 do
      if chest == 0 then
        os.pullEvent("turtle_inventory")
        chest = chest + turtle.getItemCount(16)
      else
        turtle.select(16)
        turtle.digDown()
        turtle.placeDown()
        if turtle.detectDown() then
          for i = 1,15 do
            turtle.select(i)
            turtle.dropDown()
          end
          chest = chest - 1
          turtle.select(1)
        else
          turtle.back()
          turtle.digDown()
          turtle.placeDown()
          for i = 1,15 do
            turtle.select(i)
            turtle.dropDown()
          end
        end
       end
     end
  end
  if switch == "left" then
    turtle.turnLeft()
  else
    turtle.turnRight()
  end
  turtleAPI.digForward()
  turtleAPI.digUp()
  turtle.digDown()
  if switch == "left" then
    turtle.turnLeft()
    switch = "right"
  else
    turtle.turnRight()
    switch = "left"
  end
end
*/