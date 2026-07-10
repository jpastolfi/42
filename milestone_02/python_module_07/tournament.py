from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    AggressiveStrategy,
    DefensiveStrategy,
    NormalStrategy,
    BattleStrategy,
    InvalidCreatureException
    )


def battle(matches: list[tuple[CreatureFactory, BattleStrategy]]):
    try:
        for x in range(len(matches)):
            if x + 1 == len(matches):
                break
            first_player = matches[x]
            f_factory, f_strategy = first_player
            f_creature = f_factory.create_base()
            print("* Battle *")
            print(f_creature.describe())
            print("vs")
            for y in range(x + 1, len(matches)):
                second_player = matches[y]
                s_factory, s_strategy = second_player
                s_creature = s_factory.create_base()
                print(s_creature.describe())
                print("now fight!", end="\n\n")
                f_strategy.act(f_creature)
                s_strategy.act(s_creature)
    except InvalidCreatureException as e:
        print(f"Battle error, aborting tournament: {e}")


if __name__ == "__main__":
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()
    normal = NormalStrategy()
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()
    battle([
            (healing_factory, defensive),
            (flame_factory, aggressive),
        ])
