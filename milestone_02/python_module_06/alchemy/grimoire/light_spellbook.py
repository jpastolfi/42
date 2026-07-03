from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    result: str = validate_ingredients(ingredients)
    return "Spell {}: {} ({})".format(
        "Not Recorded" if "INVALID" in result else "Recorded",
        spell_name,
        result
    )
