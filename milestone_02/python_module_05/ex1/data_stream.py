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


class DataStream():
    def __init__(self):
        self.numericProcessor = None
        self.textProcessor = None
        self.logProcessor = None

    def register_processor(self, proc: DataProcessor) -> None:
        if (isinstance(proc, NumericProcessor)):
            print("Registering Numeric Processor...")
            self.numericProcessor = proc
            print("Numeric processor registered successfully!")
        elif (isinstance(proc, TextProcessor)):
            print("Registering Text Processor...")
            self.textProcessor = proc
            print("Text processor registered successfully!")
        elif (isinstance(proc, LogProcessor)):
            print("Registering Log Processor...")
            self.logProcessor = proc
            print("Log processor registered successfully!")
        else:
            print("Unknown DataProcessor object")

    def process_stream(self, stream: list[Any]) -> None:
        print("Send batch of data on stream: {}".format(stream))
        for item in stream:
            if isinstance(item, int | float | list[int | float]):
                if self.numericProcessor:
                    self.numericProcessor.ingest(item)
                else:
                    print("No numeric processor registered")
            elif isinstance(item, str | list[str]):
                if self.textProcessor:
                    self.textProcessor.ingest(item)
                else:
                    print("No text processor registered")
            elif isinstance(item, dict[str, str] | list[dict[str, str]]):
                if self.logProcessor:
                    self.logProcessor.ingest(item)
                else:
                    print("No log processor registered")
            else:
                print("Item {} cannot be processed".format(item))

    def print_processors_stats(self) -> None:
        while self.numericProcessor.processed_data:
            index, value = self.numericProcessor.output()
            print("Numeric value {}: {}".format(index, value))
        while self.textProcessor.processed_data:
            index, value = self.textProcessor.output()
            print("Text value {}: {}".format(index, value))
        while self.logProcessor.processed_data:
            index, value = self.logProcessor.output()
            print("Log entry {}: {}".format(index, value))


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    data_stream = DataStream()
    numeric_processor = NumericProcessor()
    text_processor = TextProcessor()
    log_processor = LogProcessor()
    data_stream.register_processor(numeric_processor)
    data_stream.register_processor(text_processor)
    data_stream.register_processor(log_processor)