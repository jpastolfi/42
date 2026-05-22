def ft_plant_age() -> None:
    age_in_days: int = int(input("Enter plant age in days: "))
    ready_to_harvest: str = "Plant is ready to harvest!"
    need_more_time_str: str = "Plant needs more time to grow."
    print(ready_to_harvest if age_in_days > 60 else need_more_time_str)
