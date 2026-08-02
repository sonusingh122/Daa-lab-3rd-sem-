# Q3 — Coin Toss Simulation & Law of Large Numbers

Program to simulate a fair coin and a biased coin over many tosses, track how their observed probability of heads evolves, and plot the convergence toward their true expected values.

---

## What it does

The program simulates two coins tossed independently — one fair (`p = 0.5`) and one biased (`p` set by the user) — over a large number of trials. At every toss, it records the _running_ observed probability of heads for both coins, then plots how each converges toward its expected value as the number of tosses grows.

## Functions Overview

| Function     | Purpose                                                                                                                                                                               |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `tossCoin()` | Simulates a single toss given a bias probability — generates a random value in `[0,1]` and returns `1` (heads) if it falls below the bias, else `0` (tails). `0.5` gives a fair toss. |
| `main()`     | Drives input collection, simulation, tracking, plotting, and cleanup.                                                                                                                 |

## How It Works

1. **Input** — User provides `totalTosses` (number of tosses to simulate) and `biasProbability` (target heads probability for the biased coin, e.g. `0.7`). The bias value is validated to lie strictly between 0 and 1.
2. **Tracking setup** — Two arrays, `fairProb` and `biasedProb`, store the running probability of heads after each toss for both coins — this is what allows the convergence trend to be plotted.
3. **Simulation loop** — For each toss:
   - A fair coin toss and a biased coin toss are generated independently.
   - Running heads counts are updated for both.
   - The running probability (`heads so far / tosses so far`) is recorded for each coin.
4. **Final output** — After all tosses, the observed final probability of heads is printed for both coins.
5. **Plotting** — A GNUplot pipe is opened and configured (title, axis labels, grid, logarithmic x-axis, y-axis fixed to `[0,1]`). Four series are plotted:
   - Running probability of the fair coin
   - Running probability of the biased coin
   - A reference line at `0.5` (fair coin's expected value)
   - A reference line at `biasProbability` (biased coin's expected value)
6. **Cleanup** — The GNUplot pipe is closed and all allocated memory is freed.

## How to Run

```powershell
.\coin_toss_simulation.exe
```

You'll be prompted for:

1. **totalTosses** — number of tosses to simulate
2. **biasProbability** — the biased coin's target probability of heads (between 0 and 1)

## Output

A graph showing both coins' observed heads-probability converging toward their expected values as tosses increase — a visual demonstration of the **Law of Large Numbers**. The logarithmic x-axis helps make the early, noisier fluctuations easier to see before convergence settles in.

---

**Author:** Sonu Singh | **ID:** B125122
