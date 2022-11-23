import pandas as pd

problems = pd.read_csv(
  "/Users/anhv/projects/datastructures-algorithms-competitive-programming/problems/problems.csv",
  delimiter=";",
  header=0)

practice = pd.read_csv(
  "/Users/anhv/projects/datastructures-algorithms-competitive-programming/problems/anhv_practice.csv",
  delimiter=";",
  header=0)
success = practice[practice['result'] == 'success']
n_success = len(success)
success_problems_id = set(success["problem_id"])

available_problems = problems[~problems["id"].isin(success_problems_id)]

n_problems = len(available_problems)
rating = 1400
print(f" ====================================================================")
print(f"|                          VISUAL ASSISTANT                          |")
print(f" ====================================================================")
print(f">>> Hello. I'm Virtual Assistant to help you go to the next level.")
print(f">>> ... ")
print("\n" * 2)
print(f">>> First thing first. Let's known your self.")
print(f">>> Your rating is {rating}")
print(f">>> You have solved {n_success} problems. Woohoo!!!")
print(f">>> ...")
print("\n" * 2)
print(f">>> I have a good news. There are {n_problems} problems for you")
print(f">>> Can you code something? Try solve the following problem:")
print(available_problems.sample(1))
print(f">>> ...\n" * 5)
print(f">>> Or <{n_problems}> is not big enough. Try to find others.")
print(f">>> https://codeforces.com/problemset")
print(f">>> ...\n" * 3)
print(f">>> Good luck, my friend.")

