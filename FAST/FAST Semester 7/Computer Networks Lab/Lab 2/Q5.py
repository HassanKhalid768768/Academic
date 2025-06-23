import re

with open('domains.txt', 'r') as file:
    domains = file.readlines()

pattern = re.compile(r'\.\w+$')

for domain in domains:
    match = pattern.search(domain.strip())
    if match:
        print(f"Domain: {domain.strip()}, TLD: {match.group(0)}")

