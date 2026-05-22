def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    possibilities = {
        "packets": "{} seeds: {} packets available",
        "grams": "{} seeds: {} grams total",
        "area": "{} seeds: covers {} square meters"
    }
    if unit not in possibilities:
        print("Unknown unit type")
        return
    for p in possibilities:
        if unit == p:
            print(possibilities[p].format(seed_type, quantity))
