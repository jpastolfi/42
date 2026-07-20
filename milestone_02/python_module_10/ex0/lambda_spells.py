# map, filter, sorted, min, max, round, sum, len

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x["power"], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda n: n["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: f"* {x} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    return {
        "max_power": max(mages, key=lambda x: x["power"])["power"],
        "min_power": min(mages, key=lambda x: x["power"])["power"],
        "avg_power": round(
            sum(map(lambda n: n["power"], mages)) / len(mages),
            2)
    }


if __name__ == "__main__":
    artifacts = [
            {
                "name": "Infinity Gauntlet",
                "power": 100,
                "type": "Cosmic",
            },
            {
                "name": "The One Ring",
                "power": 80,
                "type": "Magic",
            },
    ]
    print("====================================================")
    print("Here's the list of artifacts: \n")
    for art in artifact_sorter(artifacts):
        print(
            f"{art['name']} of type {art['type']}",
            f"and a power of {art['power']}"
            )
    print("====================================================\n")
    mages = [
            {
                "name": "Merlin",
                "power": 86,
                "element": "Water",
            },
            {
                "name": "Gandalf",
                "power": 70,
                "element": "Light",
            },
            {
                "name": "Doctor Strange",
                "power": 90,
                "element": "Dark",
            }
    ]
    print("====================================================")
    print("Here's the list of filtered mages: \n")
    for mage in power_filter(mages, 80):
        print(
            f"{mage['name']} of element {mage['element']}",
            f"and a power of {mage['power']}"
            )
    print("====================================================\n")

    spells: list[str] = ["Fireball", "Blizzard", "Water blast"]
    print("====================================================")
    print("Here's the list of transformed spells: \n")
    for spell in spell_transformer(spells):
        print(spell)
    print("====================================================\n")

    print("====================================================")
    print("Here's the list of mage stats: \n")
    print(f"Most powerful power level: {mage_stats(mages)['max_power']}")
    print(f"Least powerful power level: {mage_stats(mages)['min_power']}")
    print(f"Average power level: {mage_stats(mages)['avg_power']}")
    print("====================================================\n")
