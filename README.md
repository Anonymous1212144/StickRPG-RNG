# StickRPG-RNG
There are 2 executables in the release. The blackjack.exe is the one I used for the speedrun. It takes 8 consecutive roulette numbers and find the seed, then outputs a list of cards along with the best move. This one is weird at times and does not work sometimes (more info later). The roulette.exe also takes 8 consecutive roulette numbers but this time it output the next few roulette numbers. This should work much better as long as you stay on the roulette screen. Both of these program have a very small but non-zero chance (like 1 in 2 billion) of failing to find the seed even with legitimate input, this is a bug I'm too lazy to fix lol

For blackjack.exe example, below is a screenshot of the output for my run. The last roulette number I entered is "10", which is the internal representation of the "11" shown on screen (more info later). In the actual run I saw "J4" as the first 2 cards dealt to me, so I follow the numbers on the row with "J4". 0-2 means I should hit 0-2 times, and -1 means I should skip.

![alt text](https://github.com/Anonymous1212144/StickRPG-RNG/blob/main/seed_run.png)

## The "more info"
- blackjack.exe is designed so right after you enter the last number, you start a new run as fast as possible. It also seem to fail if you have a lot of money, so try to quit with as little as possible.
- The cards shown uses "0" for 10 and "1" for A, the rest should be what you expected
- The first number in the list (before the | ) is what you should've played when you see the first 2 dealt card, but there's no bet so there's no point in following it
- The internal representation of roulette number is \<shown number>-1 for numbers from 1-36, 36 for "0", and 37 for "00"
