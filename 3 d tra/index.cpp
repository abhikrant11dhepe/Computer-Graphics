#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Structure to represent a 3D point
struct Point3D {
    float x;
    float y;
    float z;
};

// Function to perform translation of an array of 3D points using matrix
void translate(vector<Point3D> &points, float tx, float ty, float tz) {
    // Translation matrix
    float T[4][4] = {{1, 0, 0, tx},
                     {0, 1, 0, ty},
                     {0, 0, 1, tz},
                     {0, 0, 0, 1}};

    for (auto &p : points) {
        // Create augmented matrix for point
        float P[4][1] = {{p.x},
                         {p.y},
                         {p.z},
                         {1}};

        // Multiply translation matrix with point matrix
        float newPoint[4][1] = {{0},
                                {0},
                                {0},
                                {0}};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 1; ++j) {
                for (int k = 0; k < 4; ++k) {
                    newPoint[i][j] += T[i][k] * P[k][j];
                }
            }
        }

        // Update point coordinates
        p.x = newPoint[0][0];
        p.y = newPoint[1][0];
        p.z = newPoint[2][0];
    }
}

// Function to perform rotation of an array of 3D points around the x-axis
void rotateX(vector<Point3D> &points, float angle) {
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    // Rotation matrix around x-axis
    float R[4][4] = {{1, 0, 0, 0},
                     {0, cosTheta, -sinTheta, 0},
                     {0, sinTheta, cosTheta, 0},
                     {0, 0, 0, 1}};

    for (auto &p : points) {
        // Create augmented matrix for point
        float P[4][1] = {{p.x},
                         {p.y},
                         {p.z},
                         {1}};

        // Multiply rotation matrix with point matrix
        float newPoint[4][1] = {{0},
                                {0},
                                {0},
                                {0}};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 1; ++j) {
                for (int k = 0; k < 4; ++k) {
                    newPoint[i][j] += R[i][k] * P[k][j];
                }
            }
        }

        // Update point coordinates
        p.x = newPoint[0][0];
        p.y = newPoint[1][0];
        p.z = newPoint[2][0];
    }
}

// Function to perform rotation of an array of 3D points around the y-axis
void rotateY(vector<Point3D> &points, float angle) {
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    // Rotation matrix around y-axis
    float R[4][4] = {{cosTheta, 0, sinTheta, 0},
                     {0, 1, 0, 0},
                     {-sinTheta, 0, cosTheta, 0},
                     {0, 0, 0, 1}};

    for (auto &p : points) {
        // Create augmented matrix for point
        float P[4][1] = {{p.x},
                         {p.y},
                         {p.z},
                         {1}};

        // Multiply rotation matrix with point matrix
        float newPoint[4][1] = {{0},
                                {0},
                                {0},
                                {0}};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 1; ++j) {
                for (int k = 0; k < 4; ++k) {
                    newPoint[i][j] += R[i][k] * P[k][j];
                }
            }
        }

        // Update point coordinates
        p.x = newPoint[0][0];
        p.y = newPoint[1][0];
        p.z = newPoint[2][0];
    }
}

// Function to perform rotation of an array of 3D points around the z-axis
void rotateZ(vector<Point3D> &points, float angle) {
    float rad = angle * M_PI / 180.0;
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    // Rotation matrix around z-axis
    float R[4][4] = {{cosTheta, -sinTheta, 0, 0},
                     {sinTheta, cosTheta, 0, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 1}};

    for (auto &p : points) {
        // Create augmented matrix for point
        float P[4][1] = {{p.x},
                         {p.y},
                         {p.z},
                         {1}};

        // Multiply rotation matrix with point matrix
        float newPoint[4][1] = {{0},
                                {0},
                                {0},
                                {0}};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 1; ++j) {
                for (int k = 0; k < 4; ++k) {
                    newPoint[i][j] += R[i][k] * P[k][j];
                }
            }
        }

        // Update point coordinates
        p.x = newPoint[0][0];
        p.y = newPoint[1][0];
        p.z = newPoint[2][0];
    }
}

// Function to perform scaling of an array of 3D points with respect to the origin using matrix
void scale(vector<Point3D> &points, float sx, float sy, float sz) {
    // Scaling matrix
    float S[4][4] = {{sx, 0, 0, 0},
                     {0, sy, 0, 0},
                     {0, 0, sz, 0},
                     {0, 0, 0, 1}};

    for (auto &p : points) {
        // Create augmented matrix for point
        float P[4][1] = {{p.x},
                         {p.y},
                         {p.z},
                         {1}};

        // Multiply scaling matrix with point matrix
        float newPoint[4][1] = {{0},
                                {0},
                                {0},
                                {0}};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 1; ++j) {
                for (int k = 0; k < 4; ++k) {
                    newPoint[i][j] += S[i][k] * P[k][j];
                }
            }
        }

        // Update point coordinates
        p.x = newPoint[0][0];
        p.y = newPoint[1][0];
        p.z = newPoint[2][0];
    }
}

// Function to display 3D points
void displayPoints(const vector<Point3D> &points) {
    for (const auto &p : points) {
        cout << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
    }
}

int main() {
    int numPoints;
    cout << "Enter the number of points in the object: ";
    cin >> numPoints;

    vector<Point3D> points(numPoints);

    // Input for the points of the object
    for (int i = 0; i < numPoints; ++i) {
        cout << "Enter x-coordinate of point " << i+1 << ": ";
        cin >> points[i].x;
        cout << "Enter y-coordinate of point " << i+1 << ": ";
        cin >> points[i].y;
        cout << "Enter z-coordinate of point " << i+1 << ": ";
        cin >> points[i].z;
    }

    bool continueTransformation = true;

    while (continueTransformation) {
        // Ask the user which transformation to perform
        char choice;
        cout << "\nSelect Transformation:\n";
        cout << "1. Translation\n";
        cout << "2. Rotation around X-axis\n";
        cout << "3. Rotation around Y-axis\n";
        cout << "4. Rotation around Z-axis\n";
        cout << "5. Scaling\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                // Input for translation parameters
                float tx, ty, tz;
                cout << "Enter the translation along x-axis: ";
                cin >> tx;
                cout << "Enter the translation along y-axis: ";
                cin >> ty;
                cout << "Enter the translation along z-axis: ";
                cin >> tz;

                // Translation
                translate(points, tx, ty, tz);
                cout << "After Translation:" << endl;
                displayPoints(points);
                break;
            }
            case '2': {
                // Input for rotation angle around X-axis
                float angleX;
                cout << "Enter the rotation angle around X-axis in degrees: ";
                cin >> angleX;

                // Rotation around X-axis
                rotateX(points, angleX);
                cout << "After Rotation around X-axis:" << endl;
                displayPoints(points);
                break;
            }
            case '3': {
                // Input for rotation angle around Y-axis
                float angleY;
                cout << "Enter the rotation angle around Y-axis in degrees: ";
                cin >> angleY;

                // Rotation around Y-axis
                rotateY(points, angleY);
                cout << "After Rotation around Y-axis:" << endl;
                displayPoints(points);
                break;
            }
            case '4': {
                // Input for rotation angle around Z-axis
                float angleZ;
                cout << "Enter the rotation angle around Z-axis in degrees: ";
                cin >> angleZ;

                // Rotation around Z-axis
                rotateZ(points, angleZ);
                cout << "After Rotation around Z-axis:" << endl;
                displayPoints(points);
                break;
            }
            case '5': {
                // Input for scaling factors
                float sx, sy, sz;
                cout << "Enter the scaling factor along x-axis: ";
                cin >> sx;
                cout << "Enter the scaling factor along y-axis: ";
                cin >> sy;
                cout << "Enter the scaling factor along z-axis: ";
                cin >> sz;

                // Scaling
                scale(points, sx, sy, sz);
                cout << "After Scaling:" << endl;
                displayPoints(points);
                break;
            }
            case '6': {
                continueTransformation = false;
                cout << "Quitting...\n";
                break;
            }
            default:
                cout << "Invalid choice! Please select again.\n";
        }
    }

    return 0;
}
