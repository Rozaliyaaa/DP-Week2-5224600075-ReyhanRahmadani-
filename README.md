#Task 2 — Develop Your Own Core Loop


#Step 1 — Write the Core Loop


**The core loop of this program represents the main gameplay flow of the card-based system. Each round follows a fixed sequence of phases:**

The player receives a hand of cards generated randomly.
The system evaluates the hand value and calculates the base score.
Modifiers are applied to produce the final score.
Rewards (gold) are given based on the final score.
The game state is updated (total score and gold).
The shop is offered, allowing the player to obtain modifiers.
The round advances, and the loop continues until all rounds are completed.

This loop repeats until the game reaches the final round.

#Step 2 — Identify the Invariants
**1. Which steps in your loop must NEVER change order?**
The invariant structure is the fixed order of phases inside the RunSession class. The sequence:

player action → system evaluation → reward → state update → shop → next round

must always remain the same.

**2. Which components must always exist for the game to function?**
The core components that must always exist are:

RunSession (controls the loop)
ScoringSystem (handles score calculation)
RewardSystem (handles rewards)
ShopSystem (handles the shop phase)

**3. What would break if the order changes?**
If this order is changed, the game logic will break. For example, giving rewards before calculating the score would produce incorrect results, and updating the state before evaluation would lead to inconsistent behavior.

#Step 3 — Identify Mutable Elements

The mutable elements are parts of the system that can be modified without affecting the core loop:

Scoring Formula
The base score calculation in ScoringSystem (currently handValue * 10) can be changed.
Modifiers
The modifier system (e.g., DoubleScoreModifier) can be extended or replaced with new effects.
Reward Calculation
The reward formula in RewardSystem can be adjusted to change the game balance.
Shop Configuration
The shop behavior (cost, availability, purchase rules) can be modified independently.

These elements are flexible because they do not change the main structure of the loop.

#Reflection (Mandatory — 300–400 words)

**1. What is the invariant structure of your game?**
The invariant structure of this program is the core loop controlled by the RunSession class. It ensures that each round follows a consistent sequence of phases, including player action, system evaluation, reward, state update, shop, and progression to the next round. This structure is important because it keeps the system predictable and stable.

**2. What parts are mutable?**
The mutable elements include the scoring system, reward calculation, modifier effects, and shop configuration. These parts can be changed without affecting the main loop. This separation makes the program easier to maintain and extend.

**3. If you wanted to add a new feature, which class would change?**
If a new feature is added, such as a new modifier or a different scoring rule, only the related class needs to be modified. For example, changes in scoring only affect the ScoringSystem. The RunSession class remains unchanged because it only controls the flow.

**4. If you changed the loop order, what would break?**
However, if the order of the core loop is changed, the system may not work correctly. For example, applying rewards before calculating the score would result in incorrect values. This shows that maintaining the invariant structure is essential for the correctness of the program.





