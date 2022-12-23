for f in $(cd tests/; ls *.in); do
  test_id=$(echo $f | cut -d'.' -f1)
  ./solution < tests/$test_id.in | diff -aur tests/$test_id.out -
done