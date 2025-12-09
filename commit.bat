git add .
if "%1" == "" (
  git commit -m "commit by command"
) else (
  git commit -m %1
)
git branch -M main
git remote add origin https://github.com/Lamastronotte/Machionia.git
git push -u origin main