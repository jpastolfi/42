import random

class Achievement:
    def __init__(self, achievement: str) -> None:
        self.achievement = achievement
    
    def __str__(self) -> str:
        return self.achievement


class Player:
    def __init__(self, name: str) -> None:
        self.name = name
        self.achievements: set[Achievement] | None = None


def gen_player_achievements():
    my_list: list[str] = ["Strategist", "Runner", "Survivor",
                          "Hunter", "Unstoppable", "Path Finder",
                          "First Steps", "Sharp Mind", "Boss Slayer",
                          "Crafting Genius", "World Savior", "Explorer",
                          "Collector Supreme"]
    player = Player("Miguel")
    player.achievements = set(Achievement(item) for item in random.choices(my_list, k=3))
    for item in player.achievements:
        print(item)


if __name__ == "__main__":
    gen_player_achievements()
