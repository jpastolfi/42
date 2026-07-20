# map, filter, sorted, min, max, round, sum, len

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x["power"])


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
                "name": "AB",
                "power": 2,
                "type": "AB",
            },
            {
                "name": "CD",
                "power": 3,
                "type": "CD",
            },
            {
                "name": "EF",
                "power": 1,
                "type": "EF",
            }
    ]
    print("Testing artifact sorter...")
    print(artifact_sorter(artifacts))

    mages = [
            {
                "name": "AB",
                "power": 35,
                "element": "AB",
            },
            {
                "name": "CD",
                "power": 31,
                "element": "CD",
            },
            {
                "name": "EF",
                "power": 43,
                "element": "EF",
            }
    ]
    print("Testing mages filter...")
    print(power_filter(mages, 1))

    mages_names = ["AB", "CD", "EF"]

    print(spell_transformer(mages_names))

    print(mage_stats(mages))
