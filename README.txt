# Pokemon Sav Editor (PSE)
## Mionathraìm SAV

This is a command-line, GNU/Linux supported Pokemon SAV editor.

It currently only supports Pokemon Red and Blue.

I was going to go with my normal naming theme, but thought "Mionathraìm SAV"
might be too hard to type/pronounce.. So, it'll be "Pokemon Sav Editor (PSE)"
and in the sub-title we'll call it "Mionathraìm SAV".

## Why a pokemon sav editor?

PKHeX doesn't work on Linux. This does.

## Release

I did compile it using `g++ (Gentoo 12.2.1_p20230304 p13) 12.2.1 20230304`
so if that will work fine for you, go for it.


## What about other generations?

This is just a starting point. Feel free to help though.


## What about [thing you want]

Request it, give me the offset addr, or add it in yourself. This is just
something I'm doing. 


## What actually works?

You can change your name, your rival's name, and the amount of pokedollars you
have.

Right now I'm working on getting the data for editing items in the player's
pocket and I have plans to make an edit subroutine for the actual pokemon
themselves. Once the editor subroutine is finished, I will simply need to setup
the offsets per party, then per box. I'll worry about pokemon editing later
though.



## How to run

```
$ sh compile.sh
$ ./SE.o [FILENAME].sav

```

## Contribute

Make a PR.

## Where are you?

* I'm required to use 2FA apparently so if I'm not back up, that's why. I'll see
about fixing that when I can.

* I'm also working on two degrees right now. (Mathematics and Computer Science)

* I'll try to be around when I can.

## Goal

The goal of this project is to basically create a PKHeX replacement for Linux.
I want to go all the way up to modern generations, if possible.


## Nice idea

Language support for: ie_gle, ja_jp


