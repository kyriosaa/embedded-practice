export interface PackageDetails {
  name: string;
  description: string;
  readme: string;
  author: {
    email: string;
    name: string;
  };
  maintainers: {
    length: number;
    email: string;
    name: string;
  };
  license: string;
}
