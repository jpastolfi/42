def ft_water_reminder() -> None:
    days_since: int = int(input("Days since last watering: "))
    all_good: str = "Plants are fine"
    no_good: str = "Water the plants!"
    print(no_good if days_since > 2 else all_good)
