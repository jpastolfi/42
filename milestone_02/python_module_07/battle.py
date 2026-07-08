from ex0 import CreatureFactory, FlameFactory, AquaFactory


class InvalidFactoryException(Exception):
    ...


def test_factory(
        factory: CreatureFactory) -> None:
    if (not callable(factory.create_base)
            or not callable(factory.create_evolved)):
        raise InvalidFactoryException("Invalid Factory")
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())


def simulate_battle(
        first_factory: CreatureFactory,
        second_factory: CreatureFactory) -> None:
    first_creature = first_factory.create_base()
    second_creature = second_factory.create_base()
    print(f"""
{first_creature.describe()}
    vs.
{second_creature.describe()}
    fight!
{first_creature.attack()}
{second_creature.attack()}
    """)


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    try:
        test_factory(flame_factory)
        print()
        test_factory(aqua_factory)
        print()
    except InvalidFactoryException as e:
        print(e)
    simulate_battle(flame_factory, aqua_factory)
