# HoN Hero Control
Patches Heroes of Newerth to allow any other player's hero (ally or enemy) to be selected and spells cast, even though you should not have control.

This exploit was patched shortly after being reported in August 2010.

## Background
In 2010 I set up a Heroes of Newerth account during the free-to-play week and reverse engineered the game to see if there were any possible exploits. I looked to see if there was any server-side validation that was missing so an exploit could be found by bypassing the restrictions of the client. Most of the game commands were correctly validated server side such that they checked the player who issued the command was the one who owned the target hero, however for casting a spell this validation was missing. This meant you could forge a cast spell command for any player's hero and the server would accept it.

## How it Works
Injecting this DLL into Heroes of Newerth will patch the game so it will think that the player has been granted shared control of every other player's hero. This lets you select another player's hero and cast any of their spells. Note that only casting a spell works, you cannot for example move another player's hero.
