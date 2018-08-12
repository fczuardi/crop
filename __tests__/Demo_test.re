open Jest;

describe("Demo", () =>
  Expect.(test("output", () =>
            expect(Demo.output) |> toBe()
          ))
);
