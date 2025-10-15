# StickRPG-RNG
Unlike basically every Flash emulator out there, which uses LCG, the official Flash player's RNG is a third-order odd polynomial sandwiched between two xor shifts, which makes it way more difficult to reverse than LCG. They made this algorithm themselves, which is why documentation on the internet is few and far between.

There are 2 executables in the release. The blackjack.exe is the one I used for the speedrun (more info later). It takes 8 consecutive roulette numbers and finds the seed, then outputs a list of cards along with the best move. This one is weird at times and does not work sometimes (more info later). The roulette.exe also takes 8 consecutive roulette numbers but this time it outputs the next few roulette numbers. This should work much better as long as you stay on the roulette screen. Both of these programs have a very small but non-zero chance (like 8 in 2 billion) of failing to find the seed even with legitimate input, this is a bug I'm too lazy to fix lol

For blackjack.exe example, below is a screenshot of the output for my run. The last roulette number I entered is "10", which is the internal representation of the "11" shown on screen (more info later). In the actual run I saw "J4" as the first 2 cards dealt to me, so I followed the numbers on the row with "J4". 0-2 means I should hit 0-2 times, and -1 means I should skip.

![seed_run.png](https://github.com/Anonymous1212144/StickRPG-RNG/blob/main/seed_run.png)

## The "more info"
- blackjack.exe is designed so that right after you enter the last number, you start a new run as fast as possible. It also seems to fail if you have a lot of money, so try to quit with as little as possible.
- The cards shown use "0" for 10 and "1" for A, the rest should be what you expected
- The first number in the list (before the | ) is what you should've played when you see the first 2 dealt cards, but there's no bet so there's no point in following it
- The internal representation of roulette number is \<shown number>-1 for numbers from 1-36, 36 for "0", and 37 for "00"
- Watch the speedrun that destroyed the world record at the time using this tech here: https://www.speedrun.com/stick_rpg/runs/zgo60lvm

## About the Update
- Now the program will ask you for numbers until it cannot find a duplicate anymore, so you can be certain that (assuming no bugs etc), the output is the unique seed that would result in your roulette rolls
- The program no longer terminates easily now, you will probably need to press the x button or some other way to force terminate
- The very small but non-zero chance of it failing is hopefully patched
- It is now prettier! Look at this, it is beautiful lol

![seed_run2.png](https://github.com/Anonymous1212144/StickRPG-RNG/blob/main/seed_run2.png)
