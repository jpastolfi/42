from collections.abc import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combiner(target: str, power: int):
        return (spell1(target, power), spell2(target, power))
    return combiner


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplifier(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplifier


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def caster(target: str, power: int) -> str:
        if callable(condition) is True and condition(target, power):
            return spell(target, power)
        else:
            return "Spell fizzled"
    return caster


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list[str]:
        result = []
        for spell in spells:
            result.append(spell(target, power))
        return result
    return sequence


if __name__ == "__main__":
    def heal(target: str, power: int) -> str:
        return f"Heal restores {target} for {power} HP"

    def bless(target: str, power: int) -> str:
        return f"{target} has been blessed for {power} turns"

    def fireball(target: str, power: int) -> str:
        return f"{target} damages the target for {power} HP"

    print("====================================================")
    print("Testing spell combiner")
    print(spell_combiner(heal, fireball)("Dragon", 10))
    print("====================================================\n")

    print("====================================================")
    print("Testing power amplifier")
    print(power_amplifier(heal, 5)("Dragon", 10))
    print("====================================================\n")

    def is_strong(target: str, power: int) -> bool:
        if power > 5:
            return True
        return False

    print("====================================================")
    print("Testing conditional caster")
    print(conditional_caster(is_strong, fireball)("Dragon", 10))
    print("====================================================\n")

    print("====================================================")
    print("Testing spell sequence")
    print(spell_sequence([heal, bless, fireball])("Dragon", 10))
    print("====================================================\n")
