from typing import Any
from abc import ABC, abstractmethod


class NotValidatedData(Exception):
    ...


class DataProcessor(ABC):
    def __init__(self):
        self.validated_data = []
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
        is_valid: bool
        if isinstance(data, list):
            for item in data:
                print("Trying to validate input '{}':".format(item), end="")
                if isinstance(item, int | float):
                    self.validated_data.append(item)
                    is_valid = True
                else:
                    is_valid = False
                print(is_valid)
        else:
            print("Trying to validate input '{}':".format(data), end="")
            if isinstance(data, int | float):
                self.validated_data.append(data)
                is_valid = True
            else:
                is_valid = False
            print(is_valid)
        return (is_valid)

    def ingest(self, data: int | float | list[int | float]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, int | float):
                        raise NotValidatedData("Improper numeric data")
                    else:
                        self.processed_data.append(str(item))
            else:
                if not isinstance(data, int | float):
                    raise NotValidatedData("Improper numeric data")
                else:
                    self.processed_data.append(str(data))
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        print("Processing data: {}".format(self.processed_data))


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        is_valid: bool
        if isinstance(data, list):
            for item in data:
                print("Trying to validate input '{}':".format(item), end="")
                if isinstance(item, str):
                    self.validated_data.append(item)
                    is_valid = True
                else:
                    is_valid = False
                print(is_valid)
        else:
            print("Trying to validate input '{}':".format(data), end="")
            if isinstance(data, str):
                self.validated_data.append(data)
                is_valid = True
            else:
                is_valid = False
            print(is_valid)
        return (is_valid)

    def ingest(self, data: str | list[str]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, str):
                        raise NotValidatedData("Improper string data")
                    else:
                        self.processed_data.append(item)
            else:
                if not isinstance(data, str):
                    raise NotValidatedData("Improper string data")
                else:
                    self.processed_data.append(data)
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        print("Processing data: {}".format(self.processed_data))


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        is_valid: bool
        if isinstance(data, list):
            for item in data:
                print("Trying to validate input '{}':".format(item), end="")
                if (isinstance(item, dict)):
                    for unit in list(item.items()):
                        k, v = unit
                        if isinstance(k, str) and isinstance(v, str):
                            self.validated_data.append(item)
                            is_valid = True
                        else:
                            is_valid = False
                        print(is_valid)
                else:
                    is_valid = False
        else:
            print("Trying to validate input '{}':".format(data), end="")
            if (isinstance(data, dict)):
                for unit in list(data.items()):
                    k, v = unit
                    if isinstance(k, str) and isinstance(v, str):
                        self.validated_data.append(data)
                        is_valid = True
                    else:
                        is_valid = False
                    print(is_valid)
            else:
                is_valid = False
        return is_valid

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        try:
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, dict):
                        raise NotValidatedData("Improper dictionary")
                    else:
                        for unit in list(item.items()):
                            k, v = unit
                            if (not isinstance(k, str)
                                    or not isinstance(v, str)):
                                raise NotValidatedData("Improper dictionary")
                        self.processed_data.append(str(item))
            else:
                if (isinstance(data, dict)):
                    for unit in list(data.items()):
                        k, value = unit
                        if (not isinstance(k, str)
                                or not isinstance(value, str)):
                            raise NotValidatedData("Improper dictionary")
                        else:
                            self.processed_data.append(str(data))
                else:
                    raise NotValidatedData("Improper dictionary")
        except NotValidatedData as e:
            print("Got exception: {}".format(e))
        print("Processing data: {}".format(self.processed_data))


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    numericProcessor = NumericProcessor()
    numericProcessor.validate([1, 2, 3, "a"])
    numericProcessor.validate(4)
    numericProcessor.ingest([1, 2, 3, "a"])
    numericProcessor.ingest(4)
    while numericProcessor.processed_data:
        index, value = numericProcessor.output()
        print("Numeric value {}: {}".format(index, value))

    textProcessor = TextProcessor()
    textProcessor.validate(["a", "b", "c"])
    textProcessor.validate("d")
    textProcessor.ingest(["a", "b", "c"])
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
        }])
    logProcessor.ingest({
        "test5": "teste5"
    })
    logProcessor.ingest({
        "test6": 5
    })
    while logProcessor.processed_data:
        index, value = logProcessor.output()
        print("Log entry {}: {}".format(index, value))
