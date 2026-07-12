""" "What do I directly depend on?" → answered by pyproject.toml
"What exact, fully-resolved set of versions makes everything work together?"
→ answered by poetry.lock """


if __name__ == "__main__":
    try:
        import sys
        from importlib import metadata
        print("LOADING STATUS: Loading programs...", end="\n\n")
        print("Checking dependencies:")
        import pandas as pd
        pandas_v = metadata.version("pandas")
        print(f"[OK] pandas ({pandas_v})- Data manipulation ready")
        import numpy as np
        np_v = metadata.version("numpy")
        print(f"[OK] numpy ({np_v}) - Numerical computation ready")
        import matplotlib.pyplot as plt  # type: ignore
        plt_v = metadata.version("matplotlib")
        print(f"[OK] matplotlib ({plt_v}) - Visualization ready", end="\n\n")
        print("Analyzing Matrix data...")
        data = np.random.normal(loc=50, scale=15, size=1000)

        print("Processing 1000 data points...")
        series = pd.Series(data)
        mean = series.mean()
        std = series.std()

        print("Generating visualization...", end="\n\n")
        plt.hist(data, bins=100)
        plt.xlabel("Age of people in the simulation")
        plt.ylabel("Time spent online")
        plt.title(f"Distribution (mean={mean:.2f}, std={std:.2f})")
        plt.savefig("matrix_analysis.png")
        print("Analysis complete!")
        print("Results saved to: matrix_analysis.png")

    except ModuleNotFoundError as e:
        print(f"""Missing depdendencies! {e}
Please run pip install -r requirements.txt if you want to use pip
or poetry install --no-root if you want to use Poetry""")
        sys.exit(1)
