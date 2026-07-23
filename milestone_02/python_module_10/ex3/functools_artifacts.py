from typing import Any
from collections.abc import Callable
from functools import reduce, partial, lru_cache, singledispatch
from operator import add, mul


def spell_reducer(spells: list[int], operation: str) -> int:
    if len(spells) == 0:
        return len(spells)
    match operation:
        case "add":
            return reduce(add, spells)
        case "multiply":
            return reduce(mul, spells)
        case "max":
            return reduce(lambda a, b: a if a > b else b, spells)
        case "min":
            return reduce(lambda a, b: a if a < b else b, spells)
        case _:
            raise TypeError("Operation unknown")


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    first = partial(base_enchantment, 50, "Fire")
    second = partial(base_enchantment, 50, "Water")
    third = partial(base_enchantment, 50, "Earth")
    return {
        "first": first,
        "second": second,
        "third": third,
    }


@lru_cache()
def memoized_fibonacci(n: int) -> int:
    print("Fibonacci function called")
    if n <= 1:
        return n
    return memoized_fibonacci(n - 2) + memoized_fibonacci(n - 1)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def dispatcher(spell: Any):
        print("Unknown spell type")

    @dispatcher.register(int)
    def _1(spell: int):
        print(f"Damage spell: {spell} damage")

    @dispatcher.register(str)
    def _2(spell: str):
        print(f"Enchantment: {spell}")

    @dispatcher.register(list)
    def _3(spell: list):
        print(f"Multi-cast: {len(spell)} spells")

    return dispatcher


if __name__ == "__main__":
    print("""Interactive tester for scope_mysteries.""")
    print("=" * 50)
    print()

    while True:
        print("Choose an option:")
        print("0. Test spell_reducer")
        print("1. Test partial_enchanter")
        print("2. Test memoized_fibonacc")
        print("3. Test spell_dispatcher()")
        print("q. Quit")
        print()

        choice = input("Enter your choice: ").strip().lower()
        match choice:
            case "0":
                try:
                    print("=" * 50)
                    print("Testing spell reducer")
                    spell_list = [1, 2, 3, 4, 5, 6]
                    print(f"List is {spell_list}")
                    print(f"add: {spell_reducer(spell_list, 'add')}")
                    print(f"multiply: {spell_reducer(spell_list, 'multiply')}")
                    print(f"max: {spell_reducer(spell_list, 'max')}")
                    print(f"min: {spell_reducer(spell_list, 'min')}")
                    print(f"avg: {spell_reducer(spell_list, 'avg')}")
                except TypeError as e:
                    print(e)
                print("=" * 50)
            case "1":
                print("=" * 50)
                print("Testing partial enchanter")

                def enchant(power: int, element: str, target: str) -> str:
                    return f"Encant {target} with {power} {element} points!"
                partials = partial_enchanter(enchant)
                print(partials["first"]("Charmander"))
                print(partials["second"]("Squirtle"))
                print(partials["third"]("Geodude"))
                print("=" * 50)
            case "2":
                print("=" * 50)
                print("Testing memoized fibonacc")
                for i in range(20, 23):
                    print(memoized_fibonacci(i))
                    print(memoized_fibonacci.cache_info())
                print("=" * 50)
            case "3":
                print("=" * 50)
                print("Testing spell dispatcher()")
                dispatcher = spell_dispatcher()
                dispatcher(42)
                dispatcher("fireball")
                dispatcher([1, 2, 3])
                dispatcher(1.00)
                print("=" * 50)
            case _:
                print("Bye bye")
                break
