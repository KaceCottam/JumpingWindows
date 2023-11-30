# Jumping Windows

This is a simple jumping puzzle game where you try to get to the end in the least jumps possible. You can move the window in order to move the map around your player.

## Building

This is built with `CMake` and `vcpkg`. More details to come.

<details>
<summary>Project Specification</summary>

What do I need?

I want a player that can move around a map. This map has shapes with collision boxes. It also has an area where the player starts, and a win location. There may also be various graphical elements on screen, such as text.
When the player is in the air, I want to be able to move the window and find out by how much, and using that amount, shift the world around the player. Physics will apply to the player during window movement and could launch them. I could toggle this with a certain type of wall-- perhaps a "sticky" wall or floor that prevents the player from moving using the window.
I also need a jump counter that counts how many times the player has jumped. It would be nice to keep a local leaderboard so that people can compete.

I want a separated graphics and world model. My question is how to store the level data? Perhaps a level editor will be required where I can create and save levels. Levels will be stored with maybe YAML, INI or XML.

```xml
<Level>
    <Name>Demo Level</Name>
    <Style>
        <!-- This level will be in "light mode", with a red player -->
        <Background>#ffffff</Background>
        <Foreground>#000000</Foreground>
        <Sticky>#cccccc</Sticky>
        <Player>#ff00000</Player>
        <FontColor>#000000</FontColor>
    </Style>
    <!-- the user can define a zoom level. 1.0 is the default, where 1 pixel = 1 pixel -->
    <Zoom>1.0</Zoom>
    <Map>
        <!-- decorations can have either images that fit the size of the box -->
        <Decoration x=0 y=0 width=256 height=256 image="img.png" />
        <!-- or text. Text is wrapped and has a size represented in pts. -->
        <Decoration x=320 y=0 width=256 height=256 content="hello world!" size=12 />
        <!-- player spawn is required -->
        <PlayerSpawn x=0 y=0 />
        <!-- player exit is required -->
        <PlayerExit x=320 y=0 />
        <!-- boxes with collision have a center coordinate and its width and height -->
        <Box x=0 y=320 width=256 height=256 />
        <!-- boxes can be defined as sticky which stop the player upon collision and require gravity to take them off of it (when the window stops moving) or non window movement. -->
        <Box x=320 y=320 width=256 height=256 sticky=true />
    </Map>
    <ImageData>
        <!-- images will have an id that is their path, and data which is the binary data of the file base64 encoded. -->
        <Image id="img.png" data="" />
    </ImageData>
</Level>
```

This would definitely require a level editor. It should spawn a "whiteboard" with infinite bounds, that the user can pan the camera around. 
There will be an ImGui menu for choosing the current tool: pan, spawn, edit.
The spawning tool allows the user to spawn boxes, player's spawn, exit, and decorations.
The edit tool allows the user to select and drag level elements to place them, and resize using Unity-like scaling tools. The user can also use an Imgui menu to select image data, set text content, and delete elements.
There will be an ImGui menu where the user can set the zoom and level name. The user can also set the level's styles. 
Upon saving, image binary data will be base64 encoded and stored in level data-- this allows users to share levels with one file. I can use a library like imagemagick to resize images so space isn't wasted, but that is a future thing I could do.

At some point I probably want the player to have "save data" so they can progress through the campaign, but
for the prototype I will want the player to choose their level using a menu.

The main menu will have "play" which allows a player to load a level (perhaps auto discovery of levels using a specified directory will be nice) and a level editor. The level editor should be able to load previous levels as well as save new ones.
</details>