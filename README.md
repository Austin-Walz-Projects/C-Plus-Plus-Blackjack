# C++ Blackjack
This game was developed in C++ as a college student in April of 2022. This showcases full ASCII visual display of the virtual game Blackjack. The player receives two cards at the start of the game with options to Stand, Hit, or Double Down which are typical terms used in real Blackjack. Each command will do their corresponding action: Stand will go to the dealer moves, Hit will give the palyer an addtional card, and Double Down will follow hti rules but also double the bet the player has down.

The goal of Blackjack is to get as clsoe to 21 as possible without going over (this results in a bust/lost). After the player stands the dealer must continue to draw cards until either they bust or have a sum of 17 or more. If the player has a higher number than the dealer they win, if below they lose, if they have equal score they push (tie) and the player does not receive any extra money.

I have provided screenshots from the project's completion, showcasing some major development points which can be found under the Screenshot folder:


# Modular Card System: 
Implemented a generic Card template; random number generation dynamically assigned its value and suit initials. (Creating each Card Display)

# Visual Game Display: 
The game featured a visual interface, clearly displaying the dealer's hand (including a hidden 'mystery' card) at the top and the user's hand below, rather than just text descriptions. (Playing Game)

# Robust Input Validation: 
I pride myself on implementing thorough input validation (to my current knowledge) to prevent crashes, ensuring only valid user inputs were accepted throughout the game. (Menu Code, OR Playing Game (Bottom))
