from ex00 import CreatureFactory, FlameFactory, AquaFactory


class InvalidFactoryException(Exception):
    ...


fire_base_data = {
    "name": "Flameling",
    "type": "Fire",
    "technique": "Ember"
}
fire_evolved_data = {
    "name": "Pyrodon",
    "type": "Magma",
    "technique": "Magma Swm"
}
aqua_base_data = {
    "name": "Aquabub",
    "type": "Water",
    "technique": "Water Gun"
}
aqua_evolved_data = {
    "name": "Torragon",
    "type": "Ice",
    "technique": "Blizzard"
}


def test_factory(
        factory: CreatureFactory) -> None:
    if (not callable(factory.create_base)
            or not callable(factory.create_evolved)):
        raise InvalidFactoryException("Invalid Factory")
    print("Testing factory")
    base_name, base_type, base_technique = (
        fire_base_data.values()
        if isinstance(factory, FlameFactory)
        else aqua_base_data.values())
    evolved_name, evolved_type, evolved_technique = (
        fire_evolved_data.values()
        if isinstance(factory, FlameFactory)
        else aqua_evolved_data.values())
    base = factory.create_base(
        base_name, base_type, base_technique)
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved(
        evolved_name, evolved_type, evolved_technique)
    print(evolved.describe())
    print(evolved.attack())


def simulate_battle(
        flame_factory: FlameFactory, aqua_factory: AquaFactory) -> None:
    base_name, base_type, base_technique = fire_base_data.values()
    flameling = flame_factory.create_base(
        base_name, base_type, base_technique)
    base_name, base_type, base_technique = aqua_base_data.values()
    aquabub = aqua_factory.create_evolved(
        base_name, base_type, base_technique)
    print(f"""
{flameling.describe()}
    vs.
{aquabub.describe()}
    fight!
{flameling.attack()}
{aquabub.attack()}
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
