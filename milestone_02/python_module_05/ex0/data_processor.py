from typing import Any
from abc import ABC, abstractmethod


class NotValidatedData(Exception):
    ...


class DataProcessor(ABC):
    def __init__(self):
        self.processed_data = []
        self.current_item = -1

    @abstractmethod
    def validate(self, data: Any) -> bool:
        ...

    @abstractmethod
    def ingest(self, data: Any) -> None:
        ...

    def output(self) -> tuple[int, str]:
        self.current_item += 1
        return (self.current_item, self.processed_data.pop(0))


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, int | float):
                    return False
            return True
        else:
            if not isinstance(data, int | float):
                return False
            return True

    def ingest(self, data: int | float | list[int | float]) -> None:
        try:
            if not self.validate(data):
                raise NotValidatedData("Improper numeric data")
            if isinstance(data, list):
                for item in data:
                    self.processed_data.append(str(item))
            else:
                self.processed_data.append(str(data))
        except NotValidatedData as e:
            print("Got exception: {}".format(e))


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        else:
            if not isinstance(data, str):
                return False
            return True

    def ingest(self, data: str | list[str]) -> None:
        try:
            if not self.validate(data):
                raise NotValidatedData("Improper text data")
            if isinstance(data, list):
                for item in data:
                    self.processed_data.append(item)
            else:
                self.processed_data.append(data)
        except NotValidatedData as e:
            print("Got exception: {}".format(e))


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, dict):
                    return False
                for unit in list(item.items()):
                    key, value = unit
                    if not isinstance(key, str) or not isinstance(value, str):
                        return False
            return True
        else:
            if not isinstance(data, dict):
                return False
            for unit in list(data.items()):
                key, value = unit
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        try:
            if not self.validate(data):
                raise NotValidatedData("Impromer dictionary data")
            if isinstance(data, list):
                for item in data:
                    self.processed_data.append(": ".join(item.values()))
            else:
                self.processed_data.append(":".join(data.values()))
        except NotValidatedData as e:
            print("Got exception: {}".format(e))


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    numericProcessor = NumericProcessor()
    numericProcessor.ingest([1, 2, 3])
    numericProcessor.ingest([1, 2, 3, "a"])
    numericProcessor.ingest(4)
    while numericProcessor.processed_data:
        index, value = numericProcessor.output()
        print("Numeric value {}: {}".format(index, value))

    textProcessor = TextProcessor()
    textProcessor.ingest(["a", "b", "c"])
    textProcessor.ingest(["a", "b", "c", 1])
    textProcessor.ingest("d")
    while textProcessor.processed_data:
        index, value = textProcessor.output()
        print("Text value {}: {}".format(index, value))

    logProcessor = LogProcessor()
    logProcessor.validate([
     {"test1": "teste1"},
     {"test2": "teste2"},
     {"test3": "teste3"},
    ])
    logProcessor.validate({
        "test4": "teste4"
    })
    logProcessor.validate({
        "test5": 5
    })
    logProcessor.ingest([
     {"test1": "teste1"},
     {"test2": "teste2"},
     {
        "test3": "teste3",
        "test4": "teste4"
        }
    ])
    logProcessor.ingest({
        "test5": "teste5"
    })
    logProcessor.ingest({
        "test6": 5
    })
    while logProcessor.processed_data:
        index, value = logProcessor.output()
        print("Log entry {}: {}".format(index, value))
