import random


def gen_player_achievements(my_list: list[str]) -> set[str]:
    return set(random.sample(my_list, k=random.randint(1, len(my_list))))


if __name__ == "__main__":
    my_list: list[str] = [
        "Strategist", "Runner", "Survivor",
        "Hunter", "Unstoppable", "Path Finder",
        "First Steps", "Sharp Mind", "Boss Slayer",
        "Crafting Genius", "World Savior", "Explorer",
        "Collector Supreme",
        "Shadow Walker", "Iron Will", "Lone Wolf",
        "Trailblazer", "Ghost", "Silent Assassin",
        "Mastermind", "Last Stand", "Legend",
        "Dark Horse", "Overlord", "Wanderer"
        ]

    players: dict[str, set[str]] = {
            "Alice": gen_player_achievements(my_list),
            "Bob": gen_player_achievements(my_list),
            "Charlie": gen_player_achievements(my_list),
            "Dylan": gen_player_achievements(my_list)
        }

    distinct: set[str] = set()
    shared: set[str] = set(players["Alice"])

    print("=== Achievement Tracker System ===", end="\n\n")

    for player_name in players:
        print("Player {}: {}".format(
            player_name,
            players[player_name]
        ))
        distinct |= players[player_name]

    # Track unique achievements among all the players
    print("All distinct achievements: {}"
          .format(distinct), end="\n\n")

    # Find achievements shared by all players
    for player_name in players:
        shared &= players[player_name]
    print("Common achievements: {}".format(shared), end="\n\n")

    # For each player, spot the achievements no one else has
    for name, ach in players.items():
        temp: set[str] = set()
        for name_in, ach_in in players.items():
            if (name == name_in):
                continue
            temp |= ach_in
        print("Only {} has: {}".format(name, ach - temp), end="\n\n")

    # For each player, list the missing achievements to have them all
    for player in players:
        print("{} is missing: {}"
              .format(player, set(my_list) - players[player]))
