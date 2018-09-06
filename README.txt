This is a hobby project for calculating stirling numbers as cheeply as possible.
The master will be iterated upon.

iteration 2:
changed the matrix into two arrays witht the lengt n.
This saves memory for n larger than 3.

also added an if statement that skips all calculations if n = k or k = 1
(because there is only one way to place n items in 1 space or n items i n spaces)

no changes in the number of calculations needed for a stirlingnumber.

iteration 3:
added a start and stop to the internal iterator so that only the stirlingnumbers needed for a calculation
is calculated and they are only calculated once(they were only calculated once before but whatever).

Next iteration will be to minimize the space needed even further.