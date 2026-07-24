from time import time, sleep
from collections.abc import Callable
from functools import wraps
from random import random


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def timer():
        start = time()
        print(f"Casting {func.__name__}...")
        result = func()
        sleep(random())
        print(f"Spell completed in {(time() - start):.3f} seconds")
        return result

    return timer


def power_validator(min_power: int) -> Callable:
    def wrapper(func: Callable):
        @wraps(func)
        def validator(*args, **kwargs):
            power = kwargs['power'] if 'power' in kwargs else args[-1]
            if power >= min_power:
                return func(*args, **kwargs)
            else:
                return "Insufficient power for this spell"
        return validator
    return wrapper


def retry_spell(max_attempts: int) -> Callable:
    def wrapper(func: Callable):
        @wraps(func)
        def try_again():
            counter = 0
            while counter <= max_attempts:
                try:
                    return func()
                except Exception:
                    counter += 1
                    if counter > max_attempts:
                        return (
                            f"Spell casting failed after {max_attempts}"
                            " attempts"
                        )
                    else:
                        print("Spell failed, retrying... ",
                              f"(attempt {counter}/{max_attempts})")
        return try_again
    return wrapper


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < 3:
            return False
        for char in name:
            if char != " " and not char.isalpha():
                return False
        return True

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


if __name__ == "__main__":
    print("Interactive tester for decorator_mastery.")
    print("=" * 50)
    print()

    while True:
        print("Choose an option:")
        print("0. Test spell_timer")
        print("1. Test power_validator")
        print("2. Test retry_spell")
        print("3. Test MageGuild class()")
        print("q. Quit")
        print()

        choice = input("Enter your choice: ").strip().lower()
        match choice:
            case "0":
                print("=" * 50)
                print("Testing spell timer")

                def fireball():
                    return "Fireball"
                spell_timer = spell_timer(fireball)
                print(f"Result: {spell_timer()} cast!")
                print("=" * 50)
            case "1":
                print("=" * 50)
                print("Testing power validator", end="\n\n")

                @power_validator(50)
                def water_blast(power: int):
                    return f"{power} power water blast!"
                print(water_blast(49))
                print(water_blast(51))
                print("=" * 50)
            case "2":
                print("=" * 50)
                print("Testing retry spell", end="\n\n")
                print("===== Should repeat and fail =====", end="\n\n")

                @retry_spell(7)
                def fireball_exception():
                    raise ValueError
                    return "Fireball"
                print(fireball_exception(), end="\n\n")
                print("===== Should work =====", end="\n\n")

                @retry_spell(7)
                def fireball_working():
                    return "Fireball"
                print(fireball_working())
                print("=" * 50)
            case "3":
                print("=" * 50)
                print("Testing MageGuild class")
                print(MageGuild.validate_mage_name("Merlin"))
                print(MageGuild.validate_mage_name("Gu"))
                guild = MageGuild()
                print(guild.cast_spell("Lightning", power=15))
                print(guild.cast_spell("Fireball", 9))
                print("=" * 50)
            case _:
                print("Bye bye")
                break
