def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients
    valid_ingredients = light_spell_allowed_ingredients()
    current_ingredients = ingredients.split(",")
    for ingredient in valid_ingredients:
        for current in current_ingredients:
            if ingredient.lower() == current.lower():
                return "{} - VALID".format(ingredients)
    return "{} - INVALID".format(ingredients)
