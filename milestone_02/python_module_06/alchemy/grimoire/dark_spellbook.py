from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str):
    result: str = validate_ingredients(ingredients)
    return "Spell {}: {} ({})".format(
        "Not Recorded" if "INVALID" in result else "Recorded",
        spell_name,
        result
    )
