from collections.abc import Callable


def mage_counter() -> Callable:
    counter = 0

    def call():
        nonlocal counter
        counter += 1
        return counter
    return call


def spell_accumulator(initial_power: int) -> Callable:
    accumulated_power = initial_power

    def accumulator(increment: int):
        nonlocal accumulated_power
        accumulated_power += increment
        return accumulated_power
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable:
    def enchant(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return enchant


def memory_vault() -> dict[str, Callable]:
    vault = dict()

    def store(key: str, value: str) -> None:
        vault[key] = value

    def recall(key: str) -> str | None:
        return vault.get(key, "Memory not found")

    return {
        "store": store,
        "recall": recall,
    }


if __name__ == "__main__":
    print("""Interactive tester for scope_mysteries.""")
    print("=" * 50)
    print()

    while True:
        print("Choose an option:")
        print("0. Test mage_counter")
        print("1. Test spell_accumulator")
        print("2. Test enchantment_factory")
        print("3. Test memory_vault")
        print("q. Quit")
        print()

        choice = input("Enter your choice: ").strip().lower()
        match choice:
            case "0":
                print("=" * 50)
                print("Testing mage counter")
                counter_a = mage_counter()
                print(f"counter_a: {counter_a()}")
                print(f"counter_a: {counter_a()}")
                counter_b = mage_counter()
                print(f"counter_b: {counter_b()}")
                print(f"counter_b: {counter_b()}")
                print("=" * 50)
            case "1":
                print("=" * 50)
                print("Testing spell accumulator")
                accumulator = spell_accumulator(5)
                for _x in range(1, 5):
                    print(f"Power increased to {accumulator(3)}")
                print("=" * 50)
            case "2":
                print("=" * 50)
                print("Testing enchantment factory")
                flame_factory = enchantment_factory("Flaming")
                frozen_factory = enchantment_factory("Frozen")
                print(flame_factory("Sword"))
                print(flame_factory("Shield"))
                print(frozen_factory("Mace"))
                print(frozen_factory("Boots"))
                print("=" * 50)
            case "3":
                print("=" * 50)
                print("Testing memory vault")
                vault = memory_vault()
                vault["store"]("secret", 42)
                print(f"Recall 'secret': {vault['recall']('secret')}")
                print(f"Recall 'unknown': {vault['recall']('unknown')}")
                print("=" * 50)
            case _:
                print("Bye bye")
                break
