/**
 * @return {Generator<number>}
 */

var fibGenerator = function*() {
    let maxTimes = 51
    let fibs = [0, 1]
    let currId = 0
    while(maxTimes) {
        fibs.push(fibs[fibs.length - 1] + fibs[fibs.length - 2])
        maxTimes--
    }
    while(currId < 51) {
        yield fibs[currId]
        currId++
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
